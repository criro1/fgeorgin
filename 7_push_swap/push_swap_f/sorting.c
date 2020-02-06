/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:29:45 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/16 20:29:58 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_find_b(t_arr *stack, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		i++;
		stack = stack->next;
	}
	return (stack->n);
}

int		ft_find_a(t_arr *stack, int curr_b)
{
	int max_diff;
	int max_val;

	max_diff = 2147483647;
	while (stack)
	{
		if (stack->n - curr_b < max_diff && stack->n - curr_b > 0)
		{
			max_diff = stack->n - curr_b;
			max_val = stack->n;
		}
		stack = stack->next;
	}
	return (max_val);
}

void	ft_find_min(t_arr *a_st, t_arr *b_st, int **ar, int j)
{
	int		i;
	int		curr[3];

	curr[1] = ft_find_b(b_st, *ar[0]);
	curr[0] = ft_find_a(a_st, (curr)[1]);
	while (j < 4)
	{
		curr[2] = 0;
		i = ft_find_way(a_st, b_st, curr, j);
		if (i < (*ar)[2])
		{
			(*ar)[2] = i;
			(*ar)[1] = (curr)[1];
			(*ar)[5] = (curr)[0];
			(*ar)[4] = j;
		}
		j++;
	}
}

void	ft_sorting(t_arr **a_st, t_arr **b_st, int v, int *ar)
{
	int res;
	int curr[3];

	ar = (int*)malloc(sizeof(int) * 5);
	ar[3] = ft_lstlen(*b_st);
	while (*b_st)
	{
		ar[2] = 2147483647;
		ar[0] = 0;
		while (ar[0] < ar[3])
		{
			ft_find_min(*a_st, *b_st, &ar, 0);
			ar[0]++;
		}
		curr[0] = ar[5];
		curr[1] = ar[1];
		curr[2] = (v == 0) ? 2 : v;
		res = ft_choose_way(&(*a_st), &(*b_st), curr, ar[4]);
		ft_push(&(*a_st), &(*b_st));
		ft_printf("pa\n");
		ft_state(*a_st, *b_st, v, 0);
		ar[3]--;
	}
	free(ar);
}
