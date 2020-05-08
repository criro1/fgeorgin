/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:35:28 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 09:52:55 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_live(t_carriage *m_carr, t_code *i_code, t_corewar *m_cr)
{
	int		live_player;

	carriage_set_cycle_live(m_carr, params_get_cycle(m_cr->params));
	live_player = -i_code->args[arg1];
	if (live_player <= players_get_amount(m_cr->players) && live_player > 0)
	{
		param_set_player_live(m_cr->params, players_get_player(m_cr->players,
																live_player));
		package_player_say_live(live_player, m_cr->params->cycle, m_cr->fd);
	}
	param_increase_oper_live(m_cr->params);
	return (OPER_SUCCESS);
}
