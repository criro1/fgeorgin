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

void	*ft_state(t_arr *a_st, t_arr *b_st, int v)
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
	return (NULL);
}

void	three_num_a(t_arr **a_st, t_arr **b_st, int max, int v)
{
	if ((*a_st) && (*a_st)->next && (*a_st)->next->next)// && (*a_st)->next->next->next)
		while ((*a_st)->next->next->next != NULL)
		{
			if ((*a_st)->n == max)
			{
				ft_rotate(&(*a_st), NULL);
				ft_printf("ra\n", ft_state(*a_st, *b_st, v));
			}
			ft_push(b_st, a_st);
			ft_printf("pb\n", ft_state(*a_st, *b_st, v));
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

int		ft_find_b(t_arr *stack, int n, int *t)
{
	int i;

	i = 0;
	while (i < n)
	{
		i++;
		stack = stack->next;
	}
	*t = 0;
	if (i + 1 < ft_lstlen(stack) / 2 + 1)
		*t = 1;
	return (stack->n);
}

int		ft_find_a(t_arr *stack, int curr_b, int *t)
{
	int max_diff;
	int max_val;

	max_diff = 2147483647;
	// *t = 0;
	// if (j + 1 < ft_lstlen(stack) / 2 + 1)
	// 	*t = 1;
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

int 	ft_if_rra(t_arr **st1, t_arr **st2, int curr_a, int curr_b)
{
	int i;

	i = 1;
	while ((*st1)->n != curr_a && (*st2)->n != curr_b && i++)
		ft_reverse_rotate(&(*st1), &(*st2));
	while ((*st1)->n != curr_a && i++)
		ft_reverse_rotate(&(*st1), NULL);
	while ((*st2)->n != curr_b && i++)
		ft_reverse_rotate(NULL, &(*st2));
	return (i);
}

int 	ft_if_rr(t_arr **st1, t_arr **st2, int curr_a, int curr_b)
{
	int i;

	i = 1;
	while ((*st1)->n != curr_a && (*st2)->n != curr_b && i++)
		ft_rotate(&(*st1), &(*st2));
	while ((*st1)->n != curr_a && i++)
		ft_rotate(&(*st1), NULL);
	while ((*st2)->n != curr_b && i++)
		ft_rotate(NULL, &(*st2));
	return (i);
}

void	ft_find_min(t_arr *a_st, t_arr *b_st, int **ar)
{
	int t[2]; // нахожу, ниже ли середины находитя число или выше, если 0 - ниже, 1 - выше
	int	curr_a;
	int	curr_b;
	int i;
	int j;

	curr_b = ft_find_b(b_st, *ar[0], &(t[0])); // поиск значения которое проверяю
	curr_a = ft_find_a(a_st, curr_b, &(t[1])); // поиск значения в стеке а, которое надо поднять вверх
	j = 0;
	while (j < 4)
	{
		i = 1;
		if (j == 0)
		{
			i = ft_if_rra(&a_st, &b_st, curr_a, curr_b);
			// while (st1->n != curr_a && st2->n != curr_b && i++)
			// 	ft_reverse_rotate(&st1, &st2);
			// while (st1->n != curr_a && i++)
			// 	ft_reverse_rotate(&st1, NULL);
			// while (st2->n != curr_b && i++)
			// 	ft_reverse_rotate(NULL, &(st2));
		}
		else if (j == 1)
		{
			i = ft_if_rr(&a_st, &b_st, curr_a, curr_b);
		// 	while (st[0]->n != curr_a && st[1]->n != curr_b && i++)
		// 		ft_rotate(&(st[0]), &(st[1]));
		// 	while (st[0]->n != curr_a && i++)
		// 		ft_rotate(&(st[0]), NULL);
		// 	while (st[1]->n != curr_b && i++)
		// 		ft_rotate(NULL, &(st[1]));
		}
		// else if (j == 2)
		// {
		// 	while (st[0]->n != curr_a && i++)
		// 		ft_rotate(&(st[0]), NULL);
		// 	while (st[1]->n != curr_b && i++)
		// 		ft_reverse_rotate(NULL, &(st[1]));
		// }
		// else if (j == 3)
		// {
		// 	while (st[0]->n != curr_a && i++)
		// 		ft_reverse_rotate(&(st[0]), NULL);
		// 	while (st[1]->n != curr_b && i++)
		// 		ft_rotate(NULL, &(st[1]));
		// }
		if (i < (*ar)[2])
		{
			(*ar)[2] = i;
			(*ar)[1] = curr_b;
		}
		j++;
	}
	// if (t[0] == 0 && t[1] == 0)
	// {
	// 	while (a_st->n != curr_a || b_st->n != curr_b)
	// 		ft_reverse_rotate(a_st, b_st);
	// }
	// else if (t[0] == 1 && t[1] == 1)
	// {
	// 	while (a_st->n != curr_a || b_st->n != curr_b)
	// 		ft_rotate(a_st, b_st);
	// }
	// else if (t[0] == 1 && t[1] == 0)
	// {
	// 	while (a_st->n != curr_a)
	// 		ft_rotate(a_st, NULL);
	// 	while (b_st->n != curr_b)
	// 		ft_reverse_rotate(NULL, b_st);
	// }
	// else if (t[0] == 0 && t[1] == 1)
	// {
	// 	while (a_st->n != curr_a)
	// 		ft_reverse_rotate(a_st, NULL);
	// 	while (b_st->n != curr_b)
	// 		ft_rotate(NULL, b_st);
	// }
}

void	ft_sorting(t_arr **a_st, t_arr **b_st, int v)
{
	int *ar; // ar[0] - счетчик, ar[1] - значение, ar[2] - шаги, ar[3] - кол-во элементов в стеке b

	ar = (int*)malloc(sizeof(int) * 4);
	ar[3] = ft_lstlen(*b_st);
	ar[2] = 2147483647;
	while (*b_st)
	{
		ar[0] = 0;
		while (ar[0] < ar[3])
		{
			ft_find_min(*a_st, *b_st, &ar);
			ar[0]++;
		}
		ar[3]--;
		ar[2] = 2147483647;
	}
}

void	push_swap(t_arr	*a_st, int max, int v)
{
	t_arr	*b_st;

	b_st = NULL;
	ft_state(a_st, b_st, v);
	three_num_a(&a_st, &b_st, max, v);
	if (a_st && a_st->next && a_st->next->next)// && a_st->next->next->next)
		if ((a_st->next->next->n > a_st->n && a_st->next->next->n < a_st->next->n)
			|| (a_st->n > a_st->next->n && a_st->n < a_st->next->next->n)
			|| (a_st->n > a_st->next->n && a_st->next->n > a_st->next->next->n))
		{
			ft_swap(&a_st, NULL);
			ft_printf("sa\n", ft_state(a_st, b_st, v));
		}
	if (a_st && a_st->next && !a_st->next->next)
		if (a_st->n > a_st->next->n)
		{
			ft_swap(&a_st, NULL);
			ft_printf("sa\n", ft_state(a_st, b_st, v));
		}
	ft_sorting(&a_st, &b_st, v);
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
	push_swap(head, ft_max(num, ac), v);
	ft_free(head, NULL);
	return (0);
}
