/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:26:41 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 10:18:20 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			multiple_commas(char *ptr)
{
	if (*ptr && *ptr == SEPARATOR_CHAR && (*(ptr + 1) == SEPARATOR_CHAR ||
		(*(ptr - 1) == SEPARATOR_CHAR)))
		return (1);
	if (*ptr && *ptr == SEPARATOR_CHAR)
	{
		while (*ptr && ft_isspace(*ptr))
			ptr++;
		if (*ptr && *ptr == SEPARATOR_CHAR)
			return (1);
	}
	return (0);
}

static void			ft_compare_instr(char *instr,
							t_token_list **token_list, int *arg_max)
{
	if (!ft_strcmp(instr, "live") || !ft_strcmp(instr, "zjmp") ||
		!ft_strcmp(instr, "fork") || !ft_strcmp(instr, "lfork") ||
		!ft_strcmp(instr, "aff"))
		(*arg_max) = 1;
	else if (!ft_strcmp(instr, "ld") || !ft_strcmp(instr, "st") ||
		!ft_strcmp(instr, "lld"))
		(*arg_max) = 2;
	else if (!ft_strcmp(instr, "add") || !ft_strcmp(instr, "sub") ||
		!ft_strcmp(instr, "and") || !ft_strcmp(instr, "or") ||
		!ft_strcmp(instr, "xor") || !ft_strcmp(instr, "ldi") ||
		!ft_strcmp(instr, "sti") || !ft_strcmp(instr, "lldi"))
		(*arg_max) = 3;
	if (!ft_strcmp(instr, "ld") || !ft_strcmp(instr, "st") ||
		!ft_strcmp(instr, "add") || !ft_strcmp(instr, "sub") ||
		!ft_strcmp(instr, "and") || !ft_strcmp(instr, "or") ||
		!ft_strcmp(instr, "xor") || !ft_strcmp(instr, "ldi") ||
		!ft_strcmp(instr, "sti") || !ft_strcmp(instr, "lld") ||
		!ft_strcmp(instr, "lldi") || !ft_strcmp(instr, "aff"))
		(*token_list)->bc += 1;
}

static void			local_1(char **ptr, char *right)
{
	*ptr = right;
	if (ft_isspace(**ptr))
		while (ft_isspace(**ptr))
			++(*ptr);
}

static void			init(t_pa **pa, char *ptr, t_token_list *tl)
{
	(*pa)->right = ptr;
	(*pa)->save = tl->end;
	(*pa)->instr = ft_strnew(0);
	(*pa)->instr = ft_strjoin_free((*pa)->instr, tl->end->content);
	tl->bc += 1;
	ft_compare_instr((*pa)->instr, &tl, &(*pa)->arg_max);
}

void				parse_args(char *ptr, t_token_list *token_list)
{
	t_pa			*pa;

	if (!(pa = (t_pa*)ft_memalloc(sizeof(t_pa))))
		ft_exit(token_list, "malloc\n");
	init(&pa, ptr, token_list);
	while (*(pa->right))
	{
		local_1(&ptr, pa->right);
		if (*ptr == REGISTER_CHAR)
			func_reg_char(&pa, &ptr, &token_list);
		else if (*ptr == DIRECT_CHAR)
			func_direct_char(&pa, ptr, &token_list);
		else if (*ptr == LABEL_CHAR || *ptr == '-' || ft_isdigit(*ptr))
			func_label_char(&pa, ptr, &token_list);
		else if (*ptr == COMMENT_CHAR || *ptr == COMMENT_CHAR_2)
			break ;
		else if (*ptr && *ptr != SEPARATOR_CHAR)
			ft_exit(token_list, "Error: wrong symbol in arguments\n");
		else if (multiple_commas(ptr))
			ft_exit(token_list, "Bad separators\n");
		ft_end_of_while_parse_args(&token_list, &pa->arg_amount,
											&pa->right, &pa->arg_max);
	}
	ft_memdel((void**)&pa->instr);
	ft_memdel((void**)&pa);
}
