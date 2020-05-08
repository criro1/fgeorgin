/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_decrease_cycle_to_die.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:22:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/06 17:25:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	params_decrease_cycle_to_die(t_params *m_params)
{
	m_params->cycles_to_die -= CYCLE_DELTA;
}
