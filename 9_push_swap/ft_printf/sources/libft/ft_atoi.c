/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:10:56 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/29 22:11:04 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_over(size_t num, int s)
{
	if (num > 9223372036854775807 && s == -1)
		return (0);
	else if (num >= 9223372036854775807 && s == 0)
		return (-1);
	else
		return (num);
}

int				ft_atoi(const char *str)
{
	int		i;
	size_t	num;
	int		s;

	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	s = ((str[i] == '-') ? -1 : 0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = ft_over(num, s);
	return ((s == -1) ? -num : num);
}
