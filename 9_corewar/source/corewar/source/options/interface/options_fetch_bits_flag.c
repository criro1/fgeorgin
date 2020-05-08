/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_fetch_bits_flag.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:32:35 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 20:06:25 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	options_fetch_bits_flag(t_options_list *i_options)
{
	t_options_list	*iterator;
	unsigned int	o_bits_flag;

	o_bits_flag = 0;
	if ((iterator = i_options))
	{
		while (iterator)
		{
			if (*iterator->name == 'd' && !*(iterator->name + 1))
				o_bits_flag |= O_DUMP64;
			else
				o_bits_flag |= 1 << iterator->id;
			iterator = iterator->next;
		}
	}
	if (o_bits_flag & (O_SERVER | O_CLIENT))
		o_bits_flag |= O_VISU;
	return (o_bits_flag);
}
