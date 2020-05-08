/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_number_of_args_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 22:29:45 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/17 15:44:27 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			register_is_valid(char *content)
{
	if (ft_atoi(content + 1) >= 0 && ft_atoi(content + 1) <= 99)
	{
		content++;
		while (*content)
		{
			if (!ft_isdigit(*content))
			{
				ft_printf("Invalid register - %s\n", content);
				return (0);
			}
			++content;
		}
		return (1);
	}
	ft_printf("Invalid register - %s\n", content);
	return (0);
}

int			such_label_exists(t_labels *labels, char *name)
{
	while (labels)
	{
		if (!ft_strcmp(labels->name, name))
			return (1);
		labels = labels->next;
	}
	return (0);
}

int			arg_is_valid(char *token_type)
{
	if (!ft_strcmp(token_type, "register") || !ft_strcmp(token_type, "direct")
		|| !ft_strcmp(token_type, "indirect") ||
		!ft_strcmp(token_type, "dir_label") ||
		!ft_strcmp(token_type, "indir_label"))
		return (1);
	else
		return (0);
}
