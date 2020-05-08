/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_clone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:55:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:09:51 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_carriage	*carriage_clone(t_carriage *m_carriage)
{
	t_carriage	*o_clone;

	if ((o_clone = new_carriage(0, 0)))
	{
		*o_clone = *m_carriage;
		o_clone->id = -1;
	}
	else
		save_error_to_log("Carriage can't clone ", E_NO_MEM);
	return (o_clone);
}
