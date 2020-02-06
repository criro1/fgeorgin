/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:51:31 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/04 14:58:01 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void			ft_push(t_arr **head_into, t_arr **head_out)
{
	t_arr *first;

	if (head_out && (*head_out))
	{
		first = *head_out;
		*head_out = (*head_out)->next;
		first->next = *head_into;
		*head_into = first;
	}
}

void			ft_swap(t_arr **a_head, t_arr **b_head)
{
	t_arr *first;

	if (a_head && (*a_head) && (*a_head)->next)
	{
		first = *a_head;
		*a_head = (*a_head)->next;
		first->next = (*a_head)->next;
		(*a_head)->next = first;
	}
	if (b_head && (*b_head) && (*b_head)->next)
	{
		first = *b_head;
		*b_head = (*b_head)->next;
		first->next = (*b_head)->next;
		(*b_head)->next = first;
	}
}

void			ft_rotate(t_arr **a_head, t_arr **b_head)
{
	t_arr	*first;
	t_arr	*p;

	if (a_head && (*a_head) && (*a_head)->next)
	{
		first = *a_head;
		*a_head = (*a_head)->next;
		p = *a_head;
		while (p->next != NULL)
			p = p->next;
		p->next = first;
		p->next->next = NULL;
	}
	if (b_head && (*b_head) && (*b_head)->next)
	{
		first = *b_head;
		*b_head = (*b_head)->next;
		p = *b_head;
		while (p->next != NULL)
			p = p->next;
		p->next = first;
		p->next->next = NULL;
	}
}

void			ft_reverse_rotate(t_arr **a_head, t_arr **b_head)
{
	t_arr *penult;
	t_arr *p;

	if (a_head && (*a_head) && (*a_head)->next)
	{
		p = *a_head;
		while (p->next->next != NULL)
			p = p->next;
		penult = p;
		p = p->next;
		penult->next = NULL;
		p->next = *a_head;
		*a_head = p;
	}
	if (b_head && (*b_head) && (*b_head)->next)
	{
		p = *b_head;
		while (p->next->next != NULL)
			p = p->next;
		penult = p;
		p = p->next;
		penult->next = NULL;
		p->next = *b_head;
		*b_head = p;
	}
}
