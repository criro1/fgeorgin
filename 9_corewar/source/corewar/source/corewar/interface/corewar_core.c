/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:48:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/05/01 10:43:33 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar_core(t_corewar *m_corewar)
{
	int	cycle_to_check;
	int	*dump;

	cycle_to_check = 0;
	dump = NULL;
	if (g_options & O_DUMP)
		dump = get_option_obj(m_corewar->options, "d");
	while (carriages_have_live(m_corewar->carriages))
	{
		params_increase_cycle(m_corewar->params);
		package_increase_cycle(m_corewar->params->cycle, m_corewar->fd);
		corewar_exec(m_corewar);
		if (++cycle_to_check >= params_get_cycle_to_die(m_corewar->params))
		{
			corewar_check(m_corewar);
			cycle_to_check = 0;
		}
		if (dump && *dump == m_corewar->params->cycle)
		{
			memory_export_dump(m_corewar->memory, 1,
											(g_options & O_DUMP64 ? 64 : 32));
			ft_memdel((void**)&dump);
			break ;
		}
	}
}
