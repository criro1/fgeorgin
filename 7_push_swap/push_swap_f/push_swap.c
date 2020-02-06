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

#include "../header/push_swap.h"

void	ft_check_if_correct(t_arr *a_st)
{
	int i;

	i = 0;
	while (a_st)
	{
		if (a_st->next)
			if (a_st->n > a_st->next->n)
				i++;
		a_st = a_st->next;
	}
	if (i == 0)
		ft_exit(1);
}

void	ft_state(t_arr *a_st, t_arr *b_st, int v, int clear)
{
	if (clear == 2 && v == 1)
		system("clear");
	if (v == 1)
	{
		ft_printf("\nStack A:\n");
		while (a_st != NULL)
		{
			ft_printf("%d\n", a_st->n);
			a_st = a_st->next;
		}
		ft_printf("__________________________________________________________");
		ft_printf("______________________________________________________\n\n");
		ft_printf("Stack B:\n");
		while (b_st != NULL)
		{
			ft_printf("%d\n", b_st->n);
			b_st = b_st->next;
		}
		ft_printf("__________________________________________________________");
		ft_printf("______________________________________________________\n\n");
		usleep(1000000);
		if (clear == 0 || clear == 2)
			system("clear");
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
				ft_state(*a_st, *b_st, v, 0);
			}
			ft_push(b_st, a_st);
			ft_printf("pb\n");
			ft_state(*a_st, *b_st, v, 0);
		}
}

void	push_swap(t_arr **a_st, int max, int min, int v)
{
	t_arr	*b_st;

	b_st = NULL;
	ft_check_if_correct(*a_st);
	ft_state((*a_st), b_st, v, 2);
	three_num_a(&(*a_st), &b_st, max, v);
	if ((*a_st) && (*a_st)->next && (*a_st)->next->next)
		if (((*a_st)->next->next->n > (*a_st)->n && (*a_st)->next->next->n
			< (*a_st)->next->n) || ((*a_st)->n > (*a_st)->next->n && (*a_st)->n
			< (*a_st)->next->next->n) || ((*a_st)->n > (*a_st)->next->n &&
			(*a_st)->next->n > (*a_st)->next->next->n))
		{
			ft_swap(&(*a_st), NULL);
			ft_printf("sa\n");
			ft_state((*a_st), b_st, v, 0);
		}
	if ((*a_st) && (*a_st)->next && !(*a_st)->next->next)
		if ((*a_st)->n > (*a_st)->next->n)
		{
			ft_swap(&(*a_st), NULL);
			ft_printf("sa\n");
			ft_state((*a_st), b_st, v, 0);
		}
	ft_sorting(&(*a_st), &b_st, v, NULL);
	ft_screw(&(*a_st), min, v, 1);
}

int		main(int ac, char **av)
{
	t_arr	*head;
	int		num[100000];
	int		i;
	int		v;

	v = 0;
	if (ac > 1 && (!(ft_strcmp(av[1], "-v"))))
	{
		av = av + 1;
		v = 1;
	}
	head = NULL;
	head = ((ac == 1) ? NULL : ft_nums(head, 0, av + 1, num));
	if (head == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (num[i] || num[i + 1])
		ac = num[i++];
	push_swap(&head, ft_max(num, ac), ft_min(num, ac), v);
	ft_free(head, NULL);
	return (0);
}
