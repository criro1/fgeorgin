/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:26:11 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 13:51:52 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	is_number(char *i_str)
{
	char	*iterator;

	iterator = i_str;
	while (*iterator)
	{
		if (!ft_isdigit(*iterator))
			if (*iterator != '-')
				return (False);
		++iterator;
	}
	return (True);
}
