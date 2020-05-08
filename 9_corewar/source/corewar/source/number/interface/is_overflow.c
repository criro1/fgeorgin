/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:04:14 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 13:54:13 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	is_overflow(int i_value, char *i_value_ascii)
{
	char	*iterator;
	long	value;

	iterator = i_value_ascii;
	if ((value = i_value) < 0)
	{
		if (*iterator != '-')
			return (True);
		value = -value;
	}
	while (*iterator)
		++iterator;
	if (iterator < i_value_ascii)
		return (False);
	while (iterator < i_value_ascii && ft_isdigit(*iterator))
	{
		if ((value % 10 + '0') != *iterator--)
			return (True);
		value = value / 10;
	}
	return (False);
}
