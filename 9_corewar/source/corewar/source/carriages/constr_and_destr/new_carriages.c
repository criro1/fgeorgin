/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_carriages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 08:45:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/01 17:36:30 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_carriages	*new_carriages(t_memory *i_mem)
{
	t_carriages	*o_new;
	t_carriage	*new_cr;
	int			current_segment;
	int			amount_segments;

	if ((o_new = ft_memalloc(sizeof(t_carriages))))
	{
		current_segment = 0;
		amount_segments = memory_get_amount_segments(i_mem);
		while (current_segment < amount_segments)
		{
			if (!((new_cr = new_carriage((~(current_segment + 1)) + 1,
					memory_get_address_segment(i_mem, current_segment))) &&
					carriages_add_carige(o_new, new_cr)))
			{
				destroy_carriages(&o_new);
				return (NULL);
			}
			++current_segment;
		}
	}
	else
		save_error_to_log("Carriages ", NULL);
	return (o_new);
}
