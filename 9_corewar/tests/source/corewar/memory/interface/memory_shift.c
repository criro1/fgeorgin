/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:46:51 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/06 11:23:03 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		memory_shift(int i_address, int i_shift_bytes)
{
	int		raw_address;
	int		o_res_address;

	o_res_address = 0;
	raw_address = i_address + i_shift_bytes;
	if (raw_address < MEM_SIZE)
		o_res_address = raw_address;
	else
		o_res_address = raw_address % MEM_SIZE;
	return (o_res_address);
}
