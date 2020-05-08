/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_byte_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:49:49 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 15:46:36 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			magic_name_ecs_com(t_token_list *token_list)
{
	unsigned		magic_n_size;

	magic_n_size = number_reverse_mem(COREWAR_EXEC_MAGIC);
	write(token_list->fd, &magic_n_size, 4);
	write_name_fd(token_list, PROG_NAME_LENGTH);
	magic_n_size = number_reverse_mem((unsigned)(token_list->bc));
	write(token_list->fd, &magic_n_size, sizeof(magic_n_size));
	write_comment_fd(token_list, COMMENT_LENGTH);
}

static char			*null_values_and_rename(unsigned *a, unsigned *b,
													unsigned *c, char *filename)
{
	char			*new;
	char			*save;
	char			*dot;

	*a = 0;
	*b = 0;
	*c = 0;
	save = filename;
	dot = ft_strrchr(save, '.');
	new = ft_strnew(0);
	new = ft_strcpy_upto_ptr(new, save, dot);
	new = ft_strjoin_free(new, ".cor");
	ft_printf("Writing output program to %s\n", new);
	return (new);
}

static void			case_1_local(unsigned *counter, unsigned *curr_bc_tmp,
								t_token_list *tl, t_token_node *tmp)
{
	*curr_bc_tmp = write_instruction_code_fd(tmp->content, tl->fd);
	if (!ft_strcmp(tmp->content, "ld") || !ft_strcmp(tmp->content, "st") ||
	!ft_strcmp(tmp->content, "add") || !ft_strcmp(tmp->content, "sub") ||
	!ft_strcmp(tmp->content, "and") || !ft_strcmp(tmp->content, "or") ||
	!ft_strcmp(tmp->content, "xor") || !ft_strcmp(tmp->content, "ldi") ||
	!ft_strcmp(tmp->content, "sti") || !ft_strcmp(tmp->content, "lld") ||
	!ft_strcmp(tmp->content, "lldi") || !ft_strcmp(tmp->content, "aff"))
		write_args_types_code_fd(tmp, tl->fd, curr_bc_tmp);
	assign_value_to_label(tmp, tl->labels_head);
	get_bc_from_args(tmp, curr_bc_tmp);
	*counter = get_number_of_args(tmp);
}

static void			conditions_part_1_local(t_token_list *tkn_lst,
						t_token_node *tmp, unsigned *counter, unsigned *cbc_tmp)
{
	if (!ft_strcmp(tmp->type, "instruction"))
		case_1_local(counter, cbc_tmp, tkn_lst, tmp);
	else if (!ft_strcmp(tmp->type, "register"))
		write_register_fd(tmp->content, tkn_lst->fd);
	else if (!ft_strcmp(tmp->type, "direct"))
		write_direct_fd(tmp->content, tkn_lst->fd, tmp->dir_size);
	else if (!ft_strcmp(tmp->type, "indirect"))
		write_indirect_fd(tmp->content, tkn_lst->fd);
}

/*
**	cbc = current bc
*/

void				to_byte_code(t_token_list *tkn_lst, char *filename)
{
	t_token_node	*tmp;
	unsigned		cbc;
	unsigned		cbc_tmp;
	unsigned		counter;

	filename = null_values_and_rename(&cbc, &cbc_tmp, &counter, filename);
	tkn_lst->fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 00700);
	tmp = tkn_lst->head;
	magic_name_ecs_com(tkn_lst);
	while (tmp)
	{
		conditions_part_1_local(tkn_lst, tmp, &counter, &cbc_tmp);
		if (!ft_strcmp(tmp->type, "dir_label"))
			write_dir_label_fd(tmp->label_bc - cbc, tkn_lst->fd,
															tmp->dir_size);
		else if (!ft_strcmp(tmp->type, "indir_label"))
			write_indir_label_fd(tmp->label_bc - cbc, tkn_lst->fd);
		cbc += (--counter == 0) ? cbc_tmp : 0;
		tmp = tmp->next;
	}
	ft_memdel((void**)&filename);
	close(tkn_lst->fd);
}
