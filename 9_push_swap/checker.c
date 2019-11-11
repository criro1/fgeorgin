/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:29:11 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/04 15:20:46 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_line(char *line, t_arr **src, t_arr **tmp)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(src, NULL);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(NULL, tmp);
	else if (!ft_strcmp(line, "ss"))
		ft_swap(src, tmp);
	else if (!ft_strcmp(line, "pa"))
		ft_push(src, tmp);
	else if (!ft_strcmp(line, "pb"))
		ft_push(tmp, src);
	else if (!ft_strcmp(line, "ra"))
		ft_rotate(src, NULL);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate(src, tmp);
	else if (!ft_strcmp(line, "rr"))
		ft_rotate(tmp, NULL);
	else if (!ft_strcmp(line, "rra"))
		ft_reverse_rotate(src, NULL);
	else if (!ft_strcmp(line, "rrb"))
		ft_reverse_rotate(NULL, tmp);
	else if (!ft_strcmp(line, "rrr"))
		ft_reverse_rotate(src, tmp);
}

t_arr		*ft_checker(t_arr *src)
{
	t_arr	*tmp;
	t_arr	*p;
	char	*line;

	tmp = NULL;
	while (get_next_line(0, &line))
	{
		check_line(line, &src, &tmp);
		free(line);
	}
	if (tmp)
	{
		ft_free(tmp, NULL);
		return (ft_free(src, NULL));
	}
	p = src;
	while (p->next->next != NULL)
	{
		if (p->n > p->next->n)
			return (ft_free(src, NULL));
		p = p->next;
	}
	return (src);
}

int			main(int ac, char **av)
{
	t_arr	*head;
	int		num[100000];

	head = ((ac == 1) ? NULL : ft_nums(head, 0, av + 1, num));
	if (head == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	head = ft_checker(head);
	if (head == NULL)
		ft_printf("KO\n");
	else
	{
		ft_printf("OK\n");
		ft_free(head, NULL);
	}
	return (0);
}
