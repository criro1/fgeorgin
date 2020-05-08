/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_windows.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:30:06 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 03:37:26 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_info(t_visu *visu)
{
	visu->w_info = newwin(INFO_HEIGHT, INFO_WIDTH, 1, ARENA_WIDTH + 1);
	box(visu->w_info, 0, 0);
	wattrset(visu->w_info, COLOR_PAIR(COLOR_PAIR_WHITE_VISU));
	mvwprintw(visu->w_info, INFO_PAUSE_RUN_Y, 3, PAUSE_STRING);
	mvwprintw(visu->w_info, INFO_SPEED_Y, 3, "Cycles per second : %d",
														visu->keyboard->speed);
	mvwprintw(visu->w_info, 7, 3, "Exit  -> Escape (during Running)");
	mvwprintw(visu->w_info, 8, 3, "Pause -> Space");
	mvwprintw(visu->w_info, 10, 3, "SPEED -10 -> Q");
	mvwprintw(visu->w_info, 11, 3, "SPEED  -1 -> W");
	mvwprintw(visu->w_info, 12, 3, "SPEED  +1 -> E");
	mvwprintw(visu->w_info, 13, 3, "SPEED +10 -> R");
	mvwprintw(visu->w_info, 15, 3, "MAX SPEED    --> S");
	mvwprintw(visu->w_info, 16, 3, "DEFAULT SPEED -> D");
	refresh();
	wrefresh(visu->w_info);
}

static void	print_dashboard(t_visu *visu)
{
	visu->w_dashboard = newwin(DASHBOARD_HEIGHT, DASHBOARD_WIDTH,
											INFO_HEIGHT + 1, ARENA_WIDTH + 1);
	box(visu->w_dashboard, 0, 0);
	wattrset(visu->w_dashboard, COLOR_PAIR(COLOR_PAIR_WHITE_VISU));
	mvwprintw(visu->w_dashboard, DASHBOARD_CYCLE_Y, 3, "Cycle : 0");
	mvwprintw(visu->w_dashboard, DASHBOARD_PROCESSES_Y, 3, "Processes :");
	mvwprintw(visu->w_dashboard, DASHBOARD_CTD_Y, 3, "CYCLE_TO_DIE : %d",
																CYCLE_TO_DIE);
	mvwprintw(visu->w_dashboard, DASHBOARD_CYCLE_DELTA_Y, 3, "CYCLE_DELTA : %d",
																CYCLE_DELTA);
	mvwprintw(visu->w_dashboard, DASHBOARD_NBR_LIVE_Y, 3, "NBR_LIVE : %d",
																	NBR_LIVE);
	mvwprintw(visu->w_dashboard, DASHBOARD_MAX_CHECKS_Y, 3, "MAX_CHECKS : %d",
																	MAX_CHECKS);
	refresh();
	wrefresh(visu->w_dashboard);
}

void		constructor_windows(t_visu *visu)
{
	visu->w_arena = newwin(ARENA_HEIGHT, ARENA_WIDTH, 1, 1);
	box(visu->w_arena, 0, 0);
	refresh();
	wrefresh(visu->w_arena);
	print_info(visu);
	print_dashboard(visu);
}
