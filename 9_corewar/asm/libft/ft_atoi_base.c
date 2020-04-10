/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:53:40 by mwuckert          #+#    #+#             */
/*   Updated: 2019/11/05 13:55:52 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *str, int base)
{
	int	nb;
	int sign;
	int i;

	i = 0;
	nb = 0;
	sign = 1;
	while ((*str >= '\a' && *str <= '\r') || *str == ' ' || *str == '0')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F')
			|| (*str >= 'a' && *str <= 'z')) && ++i)
		if (*str >= '0' && *str <= '9')
			nb = nb * base + *str++ - '0';
		else
			nb = nb * base + (102 - *str <= 5 ? *str++ - 87 : *str++ - 55);
	if (i < 20)
		return (nb * sign);
	else if (sign == -1)
		return (0);
	return (-1);
}
