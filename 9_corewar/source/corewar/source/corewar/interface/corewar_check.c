/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:47:06 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 05:04:50 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar_check(t_corewar *m_corewar)
{
	t_itercarr	carriter;

	params_increase_number_checks(m_corewar->params);
	carriages_init_iterator(m_corewar->carriages, &carriter);
	while (carriter.have_carriage)
	{
		if (carriage_is_die(carriter.carriage,
				params_get_cycle(m_corewar->params),
					params_get_cycle_to_die(m_corewar->params)))
		{
			package_death_carriage(carriter.carriage->id,
							m_corewar->carriages->amount - 1, m_corewar->fd);
			carriages_delete_carrige(&carriter);
		}
		carriages_iterator_set_next(&carriter);
	}
	if (params_need_decrease_cycle_to_die(m_corewar->params))
	{
		params_decrease_cycle_to_die(m_corewar->params);
		if (g_options & O_VISU)
			package_decrease_ctd(m_corewar->params->cycles_to_die,
															m_corewar->fd);
	}
	params_reset(m_corewar->params);
}
