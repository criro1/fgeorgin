/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_processing_visu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:42:00 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 05:02:18 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	check_speed_change(t_visu *visu, int *prev_speed)
{
	if (*prev_speed != visu->keyboard->speed)
	{
		*prev_speed = visu->keyboard->speed;
		mvwprintw(visu->w_info, INFO_SPEED_Y, INFO_SPEED_X, "%-4d",
													visu->keyboard->speed);
		wrefresh(visu->w_info);
	}
}

static inline void	pause_key_processing(t_visu *visu)
{
	if (visu->keyboard->pause == True)
		mvwprintw(visu->w_info, INFO_PAUSE_RUN_Y, 3, PAUSE_STRING);
	else
		mvwprintw(visu->w_info, INFO_PAUSE_RUN_Y, 3, RUNNING_STRING);
	wrefresh(visu->w_info);
}

void				key_processing_visu(t_visu *visu, t_package *package,
																int *prev_speed)
{
	if (package->code_package == CODE_PACKAGE_CHANGE_CYCLES)
	{
		usleep(visu->keyboard->microseconds);
		check_speed_change(visu, prev_speed);
	}
	if (visu->keyboard->exit == True)
		visu->exit = True;
	if (visu->keyboard->pause == True)
	{
		pause_key_processing(visu);
		while (visu->keyboard->pause == True)
			check_speed_change(visu, prev_speed);
		pause_key_processing(visu);
	}
}
