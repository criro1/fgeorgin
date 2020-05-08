/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_reverse_mem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:14:20 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:54:36 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned	number_reverse_mem(unsigned i_origin_num)
{
	int				current_byte;
	unsigned		o_reverse_num;
	unsigned char	*mem_origin;
	unsigned char	*mem_reverse;

	o_reverse_num = 0;
	mem_origin = (unsigned char*)&i_origin_num;
	mem_reverse = (unsigned char*)&o_reverse_num;
	current_byte = 0;
	while (current_byte < (int)sizeof(unsigned))
	{
		mem_reverse[(sizeof(unsigned) - 1) - current_byte] =
			mem_origin[current_byte];
		++current_byte;
	}
	return (o_reverse_num);
}
