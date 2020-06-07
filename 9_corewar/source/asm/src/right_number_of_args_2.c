/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_number_of_args_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 22:02:45 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/15 22:02:47 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			right_number_of_args_3_4(int arg_n, t_token_node **token,
				t_labels *labels)
{
	int				counter;
	t_token_node	*save;

	counter = 0;
	save = *token;
	while (*token && arg_is_valid((*token)->type))
	{
		counter++;
		*token = (*token)->next;
	}
	if (counter == arg_n && (!ft_strcmp(save->type, "register")
		&& register_is_valid(save->content)) && ((!ft_strcmp(save->next->type,
		"register") && register_is_valid(save->next->content)) ||
		!ft_strcmp(save->next->type, "direct") || !ft_strcmp(save->next->type,
		"indirect") || (such_label_exists(labels, save->next->content) &&
		(!ft_strcmp(save->next->type, "indir_label") ||
		!ft_strcmp(save->next->type, "dir_label")))) &&
		((!ft_strcmp(save->next->next->type, "register") &&
		register_is_valid(save->next->next->content)) ||
		!ft_strcmp(save->next->next->type, "direct") ||
		(such_label_exists(labels, save->next->next->content) &&
		!ft_strcmp(save->next->next->type, "dir_label"))))
		return (1);
	return (0);
}

int			right_number_of_args_3_3(int arg_n, t_token_node **token,
				t_labels *labels)
{
	int				counter;
	t_token_node	*save;

	counter = 0;
	save = *token;
	while (*token && arg_is_valid((*token)->type))
	{
		counter++;
		*token = (*token)->next;
	}
	if (counter == arg_n && ((!ft_strcmp(save->type, "register")
		&& register_is_valid(save->content)) || !ft_strcmp(save->type, "direct")
		|| !ft_strcmp(save->type, "indirect") || (such_label_exists(labels,
		save->content) && (!ft_strcmp(save->type, "indir_label")
		|| !ft_strcmp(save->type, "dir_label")))) &&
		((!ft_strcmp(save->next->type, "register") &&
		register_is_valid(save->next->content)) || !ft_strcmp(save->next->type,
		"direct") || (such_label_exists(labels, save->next->content) &&
		!ft_strcmp(save->next->type, "dir_label"))) &&
		((!ft_strcmp(save->next->next->type, "register") &&
		register_is_valid(save->next->next->content))))
		return (1);
	return (0);
}

int			right_number_of_args_3_2(int arg_n, t_token_node **token,
				t_labels *labels)
{
	int				counter;
	t_token_node	*save;

	counter = 0;
	save = *token;
	while (*token && arg_is_valid((*token)->type))
	{
		counter++;
		*token = (*token)->next;
	}
	if (counter == arg_n && ((!ft_strcmp(save->type, "register")
		&& register_is_valid(save->content)) || !ft_strcmp(save->type, "direct")
		|| !ft_strcmp(save->type, "indirect") || (such_label_exists(labels,
		save->content) && (!ft_strcmp(save->type, "indir_label")
		|| !ft_strcmp(save->type, "dir_label")))) &&
		((!ft_strcmp(save->next->type, "register") &&
		register_is_valid(save->next->content)) || !ft_strcmp(save->next->type,
		"direct") || !ft_strcmp(save->next->type, "indirect") ||
		(such_label_exists(labels, save->next->content) &&
		(!ft_strcmp(save->next->type, "indir_label") ||
		!ft_strcmp(save->next->type, "dir_label")))) &&
		(!ft_strcmp(save->next->next->type, "register") &&
		register_is_valid(save->next->next->content)))
		return (1);
	return (0);
}

int			right_number_of_args_3_1(int arg_n, t_token_node **token)
{
	int				counter;
	t_token_node	*save;

	counter = 0;
	save = *token;
	while (*token && arg_is_valid((*token)->type))
	{
		counter++;
		*token = (*token)->next;
	}
	if (counter == arg_n &&
		(!ft_strcmp(save->type, "register") &&
		register_is_valid(save->content)) &&
		(!ft_strcmp(save->next->type, "register") &&
		register_is_valid(save->next->content)) &&
		(!ft_strcmp(save->next->next->type, "register") &&
		register_is_valid(save->next->next->content)))
		return (1);
	return (0);
}
