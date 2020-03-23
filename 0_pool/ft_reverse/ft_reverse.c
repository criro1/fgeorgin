/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:12:50 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/05 14:06:13 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_rev(int i, char **ac)
{
	int j;

	while (i >= 0)
	{
		while (ac[1][i] != ' ' && ac[1][i] != '\t' && i != 0)
			i--;
		if (ac[1][i] == ' ' || ac[1][i] == '\t')
			j = i + 1;
		else
			j = i;
		while (ac[1][j] != ' ' && ac[1][j] != '\t' && ac[1][j] != '\0')
		{
			ft_putchar(ac[1][j]);
			j++;
		}
		while (ac[1][i] == ' ' || ac[1][i] == '\t')
		{
			ft_putchar(ac[1][i]);
			i--;
		}
		if (i == 0)
			return (0);
		(ft_rev(i, ac));
	}
	return (0);
}

int		main(int av, char **ac)
{
	int i;

	i = 0;
	if (av != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (ac[1][i] != '\0')
		i++;
	ft_rev(i - 1, ac);
	ft_putchar('\n');
	return (0);
}
