/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:30:12 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/16 20:30:27 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_exit(int i)
{
	if (i == 0)
		write(2, "Error\n", 6);
	exit(0);
}

int		ft_strnbr(int *num, int n, int j)
{
	int i;

	i = 0;
	if (j > 0)
		while (i < j)
		{
			if (num[i] == n)
				return (0);
			i++;
		}
	return (1);
}

t_arr	*ft_free(t_arr *head, char **split)
{
	int i;

	if (head)
	{
		while (head != NULL)
		{
			free(head);
			head = head->next;
		}
		if (!split)
			return (NULL);
	}
	i = 0;
	if (split)
	{
		while (split[i])
			i++;
		while (--i >= 0)
			free(split[i]);
		free(split);
	}
	return (head);
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
