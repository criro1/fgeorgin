/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:29:15 by mwuckert          #+#    #+#             */
/*   Updated: 2019/01/14 11:22:10 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int n, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (n);
	return (n * ft_power(n, power - 1));
}
