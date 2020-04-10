/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:33:15 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/25 19:34:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_to_players(t_players *m_players, t_player *i_player)
{
	int			current_player;

	current_player = 0;
	while (current_player < MAX_PLAYERS && m_players->player[current_player])
		++current_player;
	if (current_player == MAX_PLAYERS)
	{
		ft_dprintf(STDERR_FILENO, "ERROR :%s :%s", __func__, __FILE__);
		ft_memdel((void**)&i_player);
	}
	else
	{
		m_players->player[current_player] = i_player;
		++m_players->amount;
	}
}
