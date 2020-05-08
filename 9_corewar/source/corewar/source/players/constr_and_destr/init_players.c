/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:26:05 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:32:54 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		align_players(t_players *m_pls)
{
	t_players	aligned_pls;
	int			alignment_index;
	int			aligned_index;

	ft_bzero(&aligned_pls, sizeof(t_players));
	alignment_index = 0;
	aligned_index = 0;
	while (alignment_index < MAX_PLAYERS)
	{
		if (m_pls->player[alignment_index])
		{
			aligned_pls.player[aligned_index] = m_pls->player[alignment_index];
			++aligned_pls.amount;
			++aligned_index;
		}
		++alignment_index;
	}
	*m_pls = aligned_pls;
}

static void		players_set_order(t_players *m_players)
{
	int			current;

	current = 0;
	while (current < m_players->amount)
	{
		m_players->player[current]->order = current + 1;
		++current;
	}
}

/*
**	The design for checking the validation error code was added
**	due to the requirements of the task. You can only use checking whether
**	the player has been initialized or not.
*/

t_boolean		init_players(t_players *m_players)
{
	int			current;
	int			player_error;

	current = 0;
	while (current < m_players->amount)
	{
		if ((player_error = init_player(m_players->player[current])))
		{
			if (player_error == PL_VALIDATION_ERROR)
				return (False);
			else
				destroy_player(&(m_players->player[current]));
		}
		++current;
	}
	align_players(m_players);
	players_set_order(m_players);
	return (True);
}
