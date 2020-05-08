/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_amount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 08:11:32 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 08:25:14 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			calculate_dir(t_token_list *token_list,
										char *instr, t_token_node *node)
{
	if (!ft_strcmp(instr, "zjmp") || !ft_strcmp(instr, "ldi") ||
		!ft_strcmp(instr, "sti") || !ft_strcmp(instr, "fork") ||
		!ft_strcmp(instr, "lldi") || !ft_strcmp(instr, "lfork"))
	{
		token_list->bc += 2;
		node->dir_size = 2;
	}
	else if (!ft_strcmp(instr, "live") || !ft_strcmp(instr, "ld") ||
		!ft_strcmp(instr, "and") || !ft_strcmp(instr, "or") ||
		!ft_strcmp(instr, "xor") || !ft_strcmp(instr, "lld"))
	{
		token_list->bc += 4;
		node->dir_size = 4;
	}
}

void				ft_arg_amount_3(t_token_list **token_list,
									int *arg_amount, t_token_node **save)
{
	(*arg_amount)++;
	if ((*arg_amount) == 1)
		(*save)->arg1 = indir;
	else if ((*arg_amount) == 2)
		(*save)->arg2 = indir;
	else if ((*arg_amount) == 3)
		(*save)->arg3 = indir;
	(*token_list)->bc += 2;
}

void				ft_arg_amount_2(t_token_list **token_list, int *arg_amount,
											t_token_node **save, char *instr)
{
	(*arg_amount)++;
	if ((*arg_amount) == 1)
		(*save)->arg1 = dir;
	else if ((*arg_amount) == 2)
		(*save)->arg2 = dir;
	else if ((*arg_amount) == 3)
		(*save)->arg3 = dir;
	calculate_dir((*token_list), instr, (*token_list)->end);
}

void				ft_arg_amount_1(t_token_list **token_list,
										int *arg_amount, t_token_node **save)
{
	(*arg_amount)++;
	if ((*arg_amount) == 1)
		(*save)->arg1 = reg;
	else if ((*arg_amount) == 2)
		(*save)->arg2 = reg;
	else if ((*arg_amount) == 3)
		(*save)->arg3 = reg;
	(*token_list)->bc += 1;
}
