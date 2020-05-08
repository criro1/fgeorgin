/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_introducing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:02:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/13 11:05:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	players_introducing(t_players *i_players)
{
	int		index_player;

	index_player = 0;
	ft_printf("Introducing contestants...\n");
	while (index_player < i_players->amount)
		player_introduce_yourself(i_players->player[index_player++]);
}
