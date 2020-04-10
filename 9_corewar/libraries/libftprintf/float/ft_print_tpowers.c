/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tpowers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:01:55 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/03 15:30:51 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

static void	ft_print_positive(int *positive, int *end)
{
	ft_putstr("powers positive: ");
	if (positive)
	{
		while (positive >= end)
		{
			ft_putnbr(*positive--);
			ft_putchar(' ');
		}
	}
	else
		ft_putstr("no");
	ft_putchar('\n');
}

static void	ft_print_negative(int *negative)
{
	ft_putstr("powers negative: ");
	if (negative)
	{
		while (*negative)
		{
			ft_putnbr(*negative++);
			ft_putchar(' ');
		}
	}
	else
		ft_putstr("no");
	ft_putchar('\n');
}

void		ft_print_tpowers(t_power *r)
{
	int i;

	i = 0;
	ft_putstr("powers array: ");
	while (i < 64)
	{
		ft_putnbr(r->powers[i++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_print_positive(r->positive, r->powers);
	ft_print_negative(r->negative);
}
