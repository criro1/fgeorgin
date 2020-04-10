/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:23:40 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/23 11:18:02 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_players(t_players **m_players)
{
	int index_player;

	if (m_players && *m_players)
	{
		index_player = 0;
		while (index_player < MAX_PLAYERS)
		{
			destroy_player(&(*m_players)->player[index_player]);
			++index_player;
		}
		(*m_players)->amount = 0;
		ft_memdel((void**)m_players);
	}
}
