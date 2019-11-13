/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:17:00 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/04 15:17:49 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_state(t_arr *a_st, t_arr *b_st, int v)
{
	if (v == 1)
	{
		ft_printf("\nStack A:\n");
		while (a_st != NULL)
		{
			ft_printf("%d\n", a_st->n);
			a_st = a_st->next;
		}
		ft_printf("_________________________________________________________________________________________\n\n");
		ft_printf("Stack B:\n");
		while (b_st != NULL)
		{
			ft_printf("%d\n", b_st->n);
			b_st = b_st->next;
		}
		ft_printf("_________________________________________________________________________________________\n\n");
	}
}

void	three_num_a(t_arr **a_st, t_arr **b_st, int max, int v)
{
	if ((*a_st) && (*a_st)->next && (*a_st)->next->next)
		while ((*a_st)->next->next->next != NULL)
		{
			if ((*a_st)->n == max)
			{
				ft_rotate(&(*a_st), NULL);
				ft_printf("ra\n");
				ft_state(*a_st, *b_st, v);
			}
			ft_push(b_st, a_st);
			ft_printf("pb\n");
			ft_state(*a_st, *b_st, v);
		}
}

int		ft_lstlen(t_arr *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

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
	if (curr_b >= 0)
		while (stack)
		{
			if (stack->n - curr_b < max_diff && stack->n - curr_b > 0)
			{
				max_diff = stack->n - curr_b;
				max_val = stack->n;
			}
			stack = stack->next;
		}
	if (curr_b < 0)
		while (stack)
		{
			if (curr_b - stack->n < max_diff && curr_b - stack->n > 0)
			{
				max_diff = curr_b - stack->n;
				max_val = stack->n;
			}
			stack = stack->next;
		}
	return (max_val);
}

t_arr	*ft_do_copy(t_arr *st)
{
	t_arr *tmp;
	t_arr *res;

	tmp = (t_arr*)malloc(sizeof(t_arr));
	res = tmp;
	while (st)
	{
		tmp->n = st->n;
		if (st->next)
		{
			tmp->next = (t_arr*)malloc(sizeof(t_arr));
			tmp = tmp->next;
		}
		st = st->next;
	}
	tmp->next = NULL;
	return (res);
}

int 	ft_if_rra(t_arr **st1, t_arr **st2, int *curr, int v)
{
	int i;

	i = 1;
	while ((*st1)->n != curr[0] && (*st2)->n != curr[1] && i++)
	{
		ft_reverse_rotate(&(*st1), &(*st2));
		if (v == 1 || v == 2)
			ft_printf("rrr\n");
		ft_state(*st1, *st2, v);
	}
	while (((*st1)->n != curr[0] && i++))
	{
		ft_reverse_rotate(&(*st1), NULL);
		if (v == 1 || v == 2)
			ft_printf("rra\n");
		ft_state(*st1, *st2, v);
	}
	while (((*st2)->n != curr[1] && i++))
	{
		ft_reverse_rotate(NULL, &(*st2));
		if (v == 1 || v == 2)
			ft_printf("rrb\n");
		ft_state(*st1, *st2, v);
	}
	return (i);
}

int 	ft_if_rr(t_arr **st1, t_arr **st2, int *curr, int v)
{
	int i;

	i = 1;
	while ((*st1)->n != curr[0] && (*st2)->n != curr[1] && i++)
	{
		ft_rotate(&(*st1), &(*st2));
		if (v == 1 || v == 2)
			ft_printf("rr\n");
		ft_state(*st1, *st2, v);
	}
	while (((*st1)->n != curr[0] && i++))
	{
		ft_rotate(&(*st1), NULL);
		if (v == 1 || v == 2)
			ft_printf("ra\n");
		ft_state(*st1, *st2, v);
	}
	while (((*st2)->n != curr[1] && i++))
	{
		ft_rotate(NULL, &(*st2));
		if (v == 1 || v == 2)
			ft_printf("rb\n");
		ft_state(*st1, *st2, v);
	}
	return (i);
}

int 	ft_j_2(t_arr **st1, t_arr **st2, int *curr, int v)
{
	int i;

	i = 1;
	while (((*st1)->n != curr[0] && i++))
	{
		ft_rotate(&(*st1), NULL);
		if (v == 1 || v == 2)
			ft_printf("ra\n");
		ft_state(*st1, *st2, v);
	}
	while (((*st2)->n != curr[1] && i++))
	{
		ft_reverse_rotate(NULL, &(*st2));
		if (v == 1 || v == 2)
			ft_printf("rrb\n");
		ft_state(*st1, *st2, v);
	}
	return (i);
}

int 	ft_j_3(t_arr **st1, t_arr **st2, int *curr, int v)
{
	int i;

	i = 1;
	while (((*st1)->n != curr[0] && i++))
	{
		ft_reverse_rotate(&(*st1), NULL);
		if (v == 1 || v == 2)
			ft_printf("rra\n");
		ft_state(*st1, *st2, v);
	}
	while (((*st2)->n != curr[1] && i++))
	{
		ft_rotate(NULL, &(*st2));
		if (v == 1 || v == 2)
			ft_printf("rb\n");
		ft_state(*st1, *st2, v);
	}
	return (i);
}

int 	ft_choose_way(t_arr **st1, t_arr **st2, int *curr, int j)
{
	int i;

	i = 1;
	if (j == 0)
		i = ft_if_rra(&(*st1), &(*st2), curr, curr[2]);
	else if (j == 1)
		i = ft_if_rr(&(*st1), &(*st2), curr, curr[2]);
	else if (j == 2)
		i = ft_j_2(&(*st1), &(*st2), curr, curr[2]);
	else if (j == 3)
		i = ft_j_3(&(*st1), &(*st2), curr, curr[2]);
	return (i);
}

void	ft_find_min(t_arr **a_st, t_arr **b_st, int **ar)
{
	int i;
	int j;
	t_arr *st1;
	t_arr *st2;
	int curr[3];

	(curr)[1] = ft_find_b(*b_st, *ar[0]); // поиск значения которое проверяю
	(curr)[0] = ft_find_a(*a_st, (curr)[1]); // поиск значения в стеке а, которое надо поднять вверх
	j = 0;
	while (j < 4)
	{
		st1 = ft_do_copy(*a_st);
		st2 = ft_do_copy(*b_st);
		curr[2] = 0;
		i = ft_choose_way(&(st1), &(st2), curr, j);
		if (i < (*ar)[2])
		{
			(*ar)[2] = i;
			(*ar)[1] = (curr)[1];
			(*ar)[5] = (curr)[0];
			(*ar)[4] = j;
		}
		j++;
		ft_free(st1, NULL);
		ft_free(st2, NULL);
	}
}

void	ft_sorting(t_arr **a_st, t_arr **b_st, int v)
{
	int *ar;/* ar[0] - счетчик, ar[1] - значение, ar[2] - шаги, ar[3] - кол-во элементов в стеке b */
	int res;/* ar[4] - ход, jar[5] - следующий для текущего ar[1] */
	int curr[3];

	ar = (int*)malloc(sizeof(int) * 5);
	ar[3] = ft_lstlen(*b_st);
	while (*b_st)
	{
		ar[2] = 2147483647;
		ar[0] = 0;
		while (ar[0] < ar[3])
		{
			ft_find_min(a_st, b_st, &ar);
			ar[0]++;
		}
		curr[0] = ar[5];
		curr[1] = ar[1];
		curr[2] = (v == 0) ? 2 : v;;
		res = ft_choose_way(&(*a_st), &(*b_st), curr, ar[4]);
		ft_push(&(*a_st), &(*b_st));
		ft_printf("pa\n");
		ft_state(*a_st, *b_st, v);
		ar[3]--;
	}
	free(ar);
}

void	ft_screw(t_arr **a_st, int min, int v, int i)
{
	t_arr *tmp;

	tmp = ft_do_copy(*a_st);
	while (tmp->n != min)
	{
		i++;
		tmp = tmp->next;
	}
	ft_free(tmp, NULL);
	if (i < ft_lstlen(*a_st) / 2 + 1)
		while ((*a_st)->n != min)
		{
			ft_rotate(&(*a_st), NULL);
			ft_printf("ra\n");
			ft_state(*a_st, NULL, v);	
		}
	else
		while ((*a_st)->n != min)
		{
			ft_reverse_rotate(&(*a_st), NULL);
			ft_printf("rra\n");
			ft_state(*a_st, NULL, v);	
		}
}

void	push_swap(t_arr	*a_st, int max, int min, int v)
{
	t_arr	*b_st;

	b_st = NULL;
	ft_state(a_st, b_st, v);
	three_num_a(&a_st, &b_st, max, v);
	if (a_st && a_st->next && a_st->next->next)
		if ((a_st->next->next->n > a_st->n && a_st->next->next->n < a_st->next->n)
			|| (a_st->n > a_st->next->n && a_st->n < a_st->next->next->n)
			|| (a_st->n > a_st->next->n && a_st->next->n > a_st->next->next->n))
		{
			ft_swap(&a_st, NULL);
			ft_printf("sa\n");
			ft_state(a_st, b_st, v);
		}
	if (a_st && a_st->next && !a_st->next->next)
		if (a_st->n > a_st->next->n)
		{
			ft_swap(&a_st, NULL);
			ft_printf("sa\n");
			ft_state(a_st, b_st, v);
		}
	ft_sorting(&a_st, &b_st, v);
	ft_screw(&a_st, min, v, 0);
}

int	main(int ac, char **av)
{
	t_arr	*head;
	int		num[100000];
	int		i;
	int		v;

	v = 0;
	if (ac > 1 && (!(ft_strcmp(av[1], "v")))) //rwerwerwerwerewrwerewrqwdweqrtyuitrwetyjkyujyhtgrfew
	{
		av = av + 1;
		v = 1;
	}
	head = ((ac == 1) ? NULL : ft_nums(head, 0, av + 1, num));
	if (head == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 0;
	while (num[i] || num[i + 1])
		ac = num[i++];
	push_swap(head, ft_max(num, ac), ft_min(num, ac), v);
	ft_free(head, NULL);
	return (0);
}
