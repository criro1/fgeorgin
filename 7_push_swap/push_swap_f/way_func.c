/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:30:56 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/16 20:31:07 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_if_rrr(t_arr **a_st, t_arr **b_st, int *curr, int v)
{
	int	i;

	i = 1;
	while ((*a_st)->n != curr[0] && (*b_st)->n != curr[1] && i++)
	{
		ft_reverse_rotate(&(*a_st), &(*b_st));
		if (v == 1 || v == 2)
			ft_printf("rrr\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	while (((*a_st)->n != curr[0] && i++))
	{
		ft_reverse_rotate(&(*a_st), NULL);
		if (v == 1 || v == 2)
			ft_printf("rra\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	while ((*b_st) && (*b_st)->n != curr[1] && i++)
	{
		ft_reverse_rotate(NULL, &(*b_st));
		if (v == 1 || v == 2)
			ft_printf("rrb\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	return (i);
}

int		ft_if_rr(t_arr **a_st, t_arr **b_st, int *curr, int v)
{
	int i;

	i = 1;
	while ((*a_st)->n != curr[0] && (*b_st)->n != curr[1] && i++)
	{
		ft_rotate(&(*a_st), &(*b_st));
		if (v == 1 || v == 2)
			ft_printf("rr\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	while (((*a_st)->n != curr[0] && i++))
	{
		ft_rotate(&(*a_st), NULL);
		if (v == 1 || v == 2)
			ft_printf("ra\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	while ((*b_st) && (*b_st)->n != curr[1] && i++)
	{
		ft_rotate(NULL, &(*b_st));
		if (v == 1 || v == 2)
			ft_printf("rb\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	return (i);
}

int		ft_j_2(t_arr **a_st, t_arr **b_st, int *curr, int v)
{
	int i;

	i = 1;
	while (((*a_st)->n != curr[0] && i++))
	{
		ft_rotate(&(*a_st), NULL);
		if (v == 1 || v == 2)
			ft_printf("ra\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	while (((*b_st)->n != curr[1] && i++))
	{
		ft_reverse_rotate(NULL, &(*b_st));
		if (v == 1 || v == 2)
			ft_printf("rrb\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	return (i);
}

int		ft_j_3(t_arr **a_st, t_arr **b_st, int *curr, int v)
{
	int i;

	i = 1;
	while (((*a_st)->n != curr[0] && i++))
	{
		ft_reverse_rotate(&(*a_st), NULL);
		if (v == 1 || v == 2)
			ft_printf("rra\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	while (((*b_st)->n != curr[1] && i++))
	{
		ft_rotate(NULL, &(*b_st));
		if (v == 1 || v == 2)
			ft_printf("rb\n");
		ft_state(*a_st, *b_st, v, 0);
	}
	return (i);
}

int		ft_choose_way(t_arr **a_st, t_arr **b_st, int *curr, int j)
{
	int i;

	i = 1;
	if (j == 0)
		i = ft_if_rrr(&(*a_st), &(*b_st), curr, curr[2]);
	else if (j == 1)
		i = ft_if_rr(&(*a_st), &(*b_st), curr, curr[2]);
	else if (j == 2)
		i = ft_j_2(&(*a_st), &(*b_st), curr, curr[2]);
	else if (j == 3)
		i = ft_j_3(&(*a_st), &(*b_st), curr, curr[2]);
	return (i);
}
