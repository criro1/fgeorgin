/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:43:37 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/06 19:54:29 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				clean(t_token_list *token_list)
{
	t_token_node	*tmp;
	t_token_node	*del;
	t_labels		*tmp2;
	t_labels		*del2;

	tmp = token_list->head;
	tmp2 = token_list->labels_head;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		ft_memdel((void**)&del->type);
		ft_memdel((void**)&del->content);
		ft_memdel((void**)&del);
	}
	while (tmp2)
	{
		del2 = tmp2;
		tmp2 = tmp2->next;
		ft_memdel((void**)&del2->name);
		ft_memdel((void**)&del2);
	}
	ft_memdel((void**)&token_list);
}
