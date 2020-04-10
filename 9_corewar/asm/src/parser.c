/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:30:19 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 15:39:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			check_number_of_args_2(t_token_list **token_list,
						t_token_node **token, t_labels *labels, char *name)
{
	if (!ft_strcmp(name, "ldi") || !ft_strcmp(name, "lldi"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_args_3_3(3, token, labels))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else if (!ft_strcmp(name, "sti"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_args_3_4(3, token, labels))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else
	{
		ft_exit(*token_list, "Error: no such instruction\n");
	}
}

static void			check_number_of_args_1(t_token_list **token_list,
						t_token_node **token, t_labels *labels, char *name)
{
	if (!ft_strcmp(name, "st"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_valid_args_2_2(2, token, labels))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else if (!ft_strcmp(name, "add") || !ft_strcmp(name, "sub"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_args_3_1(3, token))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else if (!ft_strcmp(name, "and") || !ft_strcmp(name, "or") ||
		!ft_strcmp(name, "xor"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_args_3_2(3, token, labels))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else
		check_number_of_args_2(token_list, token, labels, name);
}

static void			check_number_of_args(t_token_list **token_list,
						t_token_node **token, t_labels *labels)
{
	char			*name;

	name = (*token)->content;
	if (!ft_strcmp(name, "live") || !ft_strcmp(name, "zjmp") ||
		!ft_strcmp(name, "fork") || !ft_strcmp(name, "lfork"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_valid_args_1_1(1, token, labels))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else if (!ft_strcmp(name, "aff"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_valid_args_1_2(1, token))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else if (!ft_strcmp(name, "ld") || !ft_strcmp(name, "lld"))
	{
		(*token) = (*token)->next;
		if (!right_number_of_valid_args_2_1(2, token, labels))
			ft_exit(*token_list, "Error: wrong arguments for instruction\n");
	}
	else
		check_number_of_args_1(token_list, token, labels, name);
}

/*
**	checks if the file contains at least one label or one valid instruction
*/

static int			file_contains_label_or_instr(t_token_list *tl)
{
	t_token_node	*node;

	node = tl->head;
	while (node)
	{
		if ((ft_strcmp(node->type, "name") && ft_strcmp(node->type, "comment"))
			|| tl->labels_head)
			return (1);
		node = node->next;
	}
	return (0);
}

void				parser(t_token_list **token_list)
{
	t_labels		*labels;
	t_token_node	*tmp;

	labels = (*token_list)->labels_head;
	tmp = (*token_list)->head;
	if (!file_contains_label_or_instr(*token_list))
		ft_exit(*token_list, "Invalid file: not enough data\n");
	while (tmp)
	{
		if (!ft_strcmp(tmp->type, "instruction"))
			check_number_of_args(token_list, &tmp, labels);
		else
			tmp = tmp->next;
	}
}
