/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 08:09:46 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 09:21:51 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_init_player(t_visu *visu)
{
	int index;

	index = 0;
	while (index < visu->gamers.amount)
	{
		wattrset(visu->w_dashboard, COLOR_PAIR(COLOR_PAIR_WHITE_VISU));
		mvwprintw(visu->w_dashboard, DASHBOARD_PLAYER_1_Y + (index * 3), 3,
						"Player %d :", visu->gamers.player[index].number);
		mvwprintw(visu->w_dashboard, DASHBOARD_PLAYER_1_LIVE_Y + (index * 3),
															5, "Last live : 0");
		wattrset(visu->w_dashboard,
						COLOR_PAIR(visu->gamers.player[index].color_pair));
		mvwprintw(visu->w_dashboard, DASHBOARD_PLAYER_1_Y + (index * 3), 14,
										"%s", visu->gamers.player[index].name);
		index++;
	}
	wattrset(visu->w_dashboard, COLOR_PAIR(COLOR_PAIR_WHITE_VISU));
	wrefresh(visu->w_dashboard);
}
