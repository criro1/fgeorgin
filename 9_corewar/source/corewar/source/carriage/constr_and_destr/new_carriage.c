/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_carriage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:19:04 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:24:45 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_carriage		*new_carriage(t_reg i_r1_data, int i_address)
{
	t_carriage	*o_new;

	if ((o_new = ft_memalloc(sizeof(t_carriage))))
	{
		o_new->id = -1;
		o_new->address = i_address;
		o_new->reg[0] = i_r1_data;
	}
	else
		save_error_to_log("Carriage ", NULL);
	return (o_new);
}
