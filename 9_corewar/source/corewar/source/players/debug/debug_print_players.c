/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:22:38 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:53:26 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	players_print_player(int index, t_players *i_players,
															int i_space_before)
{
	print_line('_', 15, False);
	ft_printf(" Player %d ", index + 1);
	print_line('_', 15, True);
	if (i_players->player[index])
		debug_print_player(i_players->player[index], 20, 2);
	else
	{
		print_space(i_space_before);
		ft_printf("NULL\n");
	}
	print_line('-', 39, True);
}

void		debug_print_players(t_players *i_players, int indent,
															int i_space_before)
{
	int	index;

	if (i_players)
	{
		indent = 20;
		index = 0;
		print_space(i_space_before);
		ft_printf("%*s%d\n", indent, "Amount players = ", i_players->amount);
		while (index < MAX_PLAYERS)
		{
			players_print_player(index, i_players, i_space_before);
			++index;
		}
	}
	else
		printf("NULL\n");
}
