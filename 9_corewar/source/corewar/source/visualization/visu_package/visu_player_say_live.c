/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_player_say_live.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 09:37:03 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 09:59:05 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visu_player_say_live(t_package *package, t_visu *visu)
{
	long			cycle;
	int				player;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&player, content, 4);
	content += 4;
	ft_memcpy(&cycle, content, 8);
	mvwprintw(visu->w_dashboard, DASHBOARD_PLAYER_1_LIVE_Y + ((player - 1) * 3),
									DASHBOARD_PLAYER_1_LIVE_X, "%ld", cycle);
	wrefresh(visu->w_dashboard);
}
