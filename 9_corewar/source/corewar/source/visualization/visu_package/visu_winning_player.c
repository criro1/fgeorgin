/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_winning_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:47:09 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 17:30:44 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visu_winning_player(t_package *package, t_visu *visu)
{
	int				number_player;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&number_player, content, 4);
	mvwprintw(visu->w_dashboard,
		DASHBOARD_PLAYER_1_LIVE_Y + (visu->gamers.amount * 3), 3,
															"The winner is :");
	wattrset(visu->w_dashboard,
				COLOR_PAIR(visu->gamers.player[number_player - 1].color_pair));
	mvwprintw(visu->w_dashboard,
		DASHBOARD_PLAYER_1_LIVE_Y + (visu->gamers.amount * 3), 19,
							"%s", visu->gamers.player[number_player - 1].name);
	wattrset(visu->w_dashboard, COLOR_PAIR(COLOR_PAIR_WHITE_VISU));
	mvwprintw(visu->w_dashboard,
		DASHBOARD_PLAYER_1_LIVE_Y + (visu->gamers.amount * 3) + 2, 3,
													"Press Escape to finish");
	wrefresh(visu->w_dashboard);
}
