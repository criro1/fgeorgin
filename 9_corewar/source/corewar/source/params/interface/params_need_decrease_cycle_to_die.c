/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_need_decrease_cycle_to_die.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:13:09 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 19:50:15 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	params_need_decrease_cycle_to_die(t_params *i_params)
{
	if (i_params->num_oper_live >= NBR_LIVE ||
					i_params->number_checks >= MAX_CHECKS)
		return (True);
	return (False);
}
