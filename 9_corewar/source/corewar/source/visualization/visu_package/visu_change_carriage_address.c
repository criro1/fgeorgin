/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_change_carriage_address.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:58:49 by astamm            #+#    #+#             */
/*   Updated: 2020/03/16 18:03:03 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visu_change_carriage_address(t_visu *visu, t_visu_carriage *carriage)
{
	chtype	ch;

	mvwinnstr(visu->w_arena, carriage->y, carriage->x,
													carriage->original_str, 2);
	ch = mvwinch(visu->w_arena, carriage->y, carriage->x);
	carriage->color_pair_txt = PAIR_NUMBER(ch);
	if (carriage->color_pair_txt > AMOUNT_COLOR_PAIRS)
		carriage->color_pair_txt -= AMOUNT_COLOR_PAIRS;
	wattrset(visu->w_arena, COLOR_PAIR(carriage->color_pair_txt));
	mvwprintw(visu->w_arena, carriage->y, carriage->x, carriage->original_str);
	set_y_x(&carriage->y, &carriage->x, carriage->address, visu);
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
