/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_player_to_players.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:02:03 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:43:20 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		insert_player_to_players(t_players *m_players,
												t_player *i_player, int i_order)
{
	m_players->player[i_order] = i_player;
	++m_players->amount;
}

static void		push_to_end(t_players *m_players, t_player *i_player)
{
	int			index;

	index = 0;
	while (index < MAX_PLAYERS && m_players->player[index])
		++index;
	if (index == MAX_PLAYERS)
		save_error_to_log("Too many players (amount != real)", "players");
	else
		insert_player_to_players(m_players, i_player, index);
}

static void		move_players(t_players *m_players, int order)
{
	int	insert_place;
	int	insert_item;

	insert_place = order;
	while (insert_place < MAX_PLAYERS && m_players->player[insert_place])
		++insert_place;
	if ((insert_item = insert_place - 1) < 0 || insert_place == MAX_PLAYERS)
		save_error_to_log("Problem with move player", "players");
	else
	{
		while (insert_place != order)
		{
			m_players->player[insert_place] = m_players->player[insert_item];
			m_players->player[insert_item] = NULL;
			--insert_item;
			--insert_place;
		}
	}
}

void			push_player_to_players(t_players *m_players,
										t_player *i_insert_player, int i_order)
{
	if (i_insert_player->order > MAX_PLAYERS)
		save_error_to_log("Add to big order", "players");
	else if (m_players->amount >= MAX_PLAYERS)
		save_error_to_log("Too many players", "players");
	else if (i_order == NO_ORDER_PLAYER)
		push_to_end(m_players, i_insert_player);
	else if (!m_players->player[i_order])
		insert_player_to_players(m_players, i_insert_player, i_order);
	else
	{
		move_players(m_players, i_order);
		insert_player_to_players(m_players, i_insert_player, i_order);
	}
}
