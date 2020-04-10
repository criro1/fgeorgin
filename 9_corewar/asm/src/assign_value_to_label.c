/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_value_to_label.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:35:22 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 02:45:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		case_1_local(t_token_node *node, t_labels *labels)
{
	t_labels	*labels_tmp;

	if (!ft_strcmp(node->next->type, "dir_label") ||
					!ft_strcmp(node->next->type, "indir_label"))
	{
		labels_tmp = labels;
		while (labels_tmp)
		{
			if (!ft_strcmp(labels_tmp->name, node->next->content))
			{
				node->next->label_bc = labels_tmp->bc;
				break ;
			}
			labels_tmp = labels_tmp->next;
		}
	}
}

static void		case_2_local(t_token_node *node, t_labels *labels)
{
	t_labels	*labels_tmp;

	if (!ft_strcmp(node->next->next->type, "dir_label") ||
				!ft_strcmp(node->next->next->type, "indir_label"))
	{
		labels_tmp = labels;
		while (labels_tmp)
		{
			if (!ft_strcmp(labels_tmp->name, node->next->next->content))
			{
				node->next->next->label_bc = labels_tmp->bc;
				break ;
			}
			labels_tmp = labels_tmp->next;
		}
	}
}

static void		case_3_local(t_token_node *node, t_labels *labels)
{
	t_labels	*labels_tmp;

	if (!ft_strcmp(node->next->next->next->type, "dir_label") ||
				!ft_strcmp(node->next->next->next->type, "indir_label"))
	{
		labels_tmp = labels;
		while (labels_tmp)
		{
			if (!ft_strcmp(labels_tmp->name, node->next->next->next->content))
			{
				node->next->next->next->label_bc = labels_tmp->bc;
				break ;
			}
			labels_tmp = labels_tmp->next;
		}
	}
}

void			assign_value_to_label(t_token_node *node, t_labels *labels)
{
	if (node->arg1 == dir || node->arg1 == indir)
		case_1_local(node, labels);
	if (node->arg2 == dir || node->arg2 == indir)
		case_2_local(node, labels);
	if (node->arg3 == dir || node->arg3 == indir)
		case_3_local(node, labels);
}
