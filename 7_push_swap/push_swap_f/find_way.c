/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:23:16 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/12/12 22:23:18 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_if_rrr_w(t_arr *a_st, t_arr *b_st, int a, int b)
{
	int		i;

	i = 1;
	while (a_st->n != a)
		a_st = a_st->next;
	while (b_st->n != b)
		b_st = b_st->next;
	while (a_st != NULL && b_st != NULL && i++)
	{
		a_st = a_st->next;
		b_st = b_st->next;
	}
	while (a_st != NULL && i++)
		a_st = a_st->next;
	while (b_st != NULL && i++)
		b_st = b_st->next;
	return (i);
}

int		ft_if_rr_w(t_arr *a_st, t_arr *b_st, int a, int b)
{
	int		i;

	i = 1;
	while (a_st->n != a && b_st->n != b && i++)
	{
		a_st = a_st->next;
		b_st = b_st->next;
	}
	while (a_st->n != a && i++)
		a_st = a_st->next;
	while (b_st->n != b && i++)
		b_st = b_st->next;
	return (i);
}

int		ft_j_2_w(t_arr *a_st, t_arr *b_st, int a, int b)
{
	int		i;

	i = 1;
	while (a_st->n != a && i++)
		a_st = a_st->next;
	while (b_st->n != b)
		b_st = b_st->next;
	while (b_st != NULL && i++)
		b_st = b_st->next;
	return (i);
}

int		ft_j_3_w(t_arr *a_st, t_arr *b_st, int a, int b)
{
	int		i;

	i = 1;
	while (a_st->n != a)
		a_st = a_st->next;
	while (a_st != NULL && i++)
		a_st = a_st->next;
	while (b_st->n != b && i++)
		b_st = b_st->next;
	return (i);
}

int		ft_find_way(t_arr *a_st, t_arr *b_st, int *curr, int j)
{
	int i;

	i = 1;
	if (j == 0)
		i = ft_if_rrr_w(a_st, b_st, curr[0], curr[1]);
	else if (j == 1)
		i = ft_if_rr_w(a_st, b_st, curr[0], curr[1]);
	else if (j == 2)
		i = ft_j_2_w(a_st, b_st, curr[0], curr[1]);
	else if (j == 3)
		i = ft_j_3_w(a_st, b_st, curr[0], curr[1]);
	return (i);
}
