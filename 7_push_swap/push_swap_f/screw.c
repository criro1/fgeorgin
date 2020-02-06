/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:57:56 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/16 20:58:04 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_if_a_st_n(t_arr **a_st, int min, int v)
{
	if ((*a_st)->n == min)
		ft_state(*a_st, NULL, v, 1);
	else
		ft_state(*a_st, NULL, v, 0);
}

void	ft_screw(t_arr **a_st, int min, int v, int i)
{
	t_arr *tmp;

	tmp = (*a_st);
	while (tmp->n != min && i++)
		tmp = tmp->next;
	if (i - 1 < ft_lstlen(*a_st) / 2 + 1)
		while ((*a_st)->n != min)
		{
			ft_rotate(&(*a_st), NULL);
			ft_printf("ra\n");
			ft_if_a_st_n(a_st, min, v);
		}
	else
		while ((*a_st)->n != min)
		{
			ft_reverse_rotate(&(*a_st), NULL);
			ft_printf("rra\n");
			ft_if_a_st_n(a_st, min, v);
		}
}
