/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_get_address_segment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:59:12 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/01 17:14:06 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		memory_get_address_segment(t_memory *i_mem, int i_segment)
{
	if (i_segment >= 0 && i_segment < i_mem->amount_segments)
		return (i_mem->segments[i_segment]);
	else
		save_error_to_log("Memory ", "Invalid segment __func__");
	return (-1);
}
