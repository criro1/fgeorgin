/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:10:47 by astamm            #+#    #+#             */
/*   Updated: 2019/12/14 13:21:51 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (ft_isspace((int)(*str)))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit((int)(*str)))
	{
		if ((nb * 10 + *str - '0') / 10 == nb)
			nb = nb * 10 + *str++ - '0';
		else if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return ((int)nb * sign);
}
