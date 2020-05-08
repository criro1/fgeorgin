/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_new_carriage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:01:45 by astamm            #+#    #+#             */
/*   Updated: 2020/03/16 16:25:43 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visu_new_carriage(t_visu *visu, t_visu_carriage *carriage)
{
	chtype	ch;

	set_y_x(&carriage->y, &carriage->x, carriage->address,
															visu);
	mvwinnstr(visu->w_arena, carriage->y, carriage->x,
													carriage->original_str, 2);
	ch = mvwinch(visu->w_arena, carriage->y, carriage->x);
	carriage->color_pair_txt = PAIR_NUMBER(ch);
	if (carriage->color_pair_txt > AMOUNT_COLOR_PAIRS)
		carriage->color_pair_txt -= AMOUNT_COLOR_PAIRS;
	carriage->color_pair = carriage->color_pair_txt + AMOUNT_COLOR_PAIRS;
	wattrset(visu->w_arena, COLOR_PAIR(carriage->color_pair));
	mvwprintw(visu->w_arena, carriage->y, carriage->x, carriage->original_str);
	wrefresh(visu->w_arena);
}
