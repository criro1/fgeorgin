/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:34:30 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/03 12:26:44 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	corewar_dump_mode(t_corewar *m_corewar)
{
	int			cycle_dump;
	int			*obj_d;
	t_boolean	have_live_carriage;

	obj_d = get_option_obj(&m_corewar->options, "d");
	cycle_dump = *obj_d;
	ft_memdel((void**)&obj_d);
	have_live_carriage = True;
	while (have_live_carriage && cycle_dump != m_corewar->params->cycle);
	{
		if (params_need_check(m_corewar->params))
			have_live_carriage = corewar_check(m_corewar);
	}
}

static corewar_default_mode(t_corewar *m_corewar)
{
	int	cycle_to_check;

	cycle_to_check = 0;
	while (carriages_have_live(m_corewar->carriages))
	{
		corewar_exec(m_corewar);
		if (cycle_to_check++ < params_get_cycle_to_die(m_corewar->params))
		{
			corewar_check(m_corewar);
			cycle_to_check = 0;
		}
	}
}

int		corewar_run(t_corewar *m_corewar)
{
	if (options_is(m_corewar->options, OPT_DUMP))
		corewar_dump_mode(corewar);
	else if (options_is(m_corewar->options, OPT_VISUAL))
		corewar_visual_mode(corewar);
}
