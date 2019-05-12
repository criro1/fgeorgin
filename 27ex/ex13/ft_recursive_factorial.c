/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:14:52 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/05 12:30:05 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int i;

	i = nb;
	if (i < 0 || i > 12)
		return (0);
	if (i == 0)
		return (1);
	i = i * ft_recursive_factorial(i - 1);
	return (i);
}
