/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_death_carriage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:10:27 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 11:38:38 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	add_function(t_visu *visu, int *color_pair_txt, int id_car)
{
	chtype	ch;

	mvwinnstr(visu->w_arena, visu->struct_carriages.carriages[id_car]->y,
			visu->struct_carriages.carriages[id_car]->x,
					visu->struct_carriages.carriages[id_car]->original_str, 2);
	ch = mvwinch(visu->w_arena, visu->struct_carriages.carriages[id_car]->y,
								visu->struct_carriages.carriages[id_car]->x);
	*color_pair_txt = PAIR_NUMBER(ch);
	if (*color_pair_txt > AMOUNT_COLOR_PAIRS)
		*color_pair_txt -= AMOUNT_COLOR_PAIRS;
	visu->struct_carriages.carriages[id_car]->color_pair_txt = *color_pair_txt;
}

void				visu_death_carriage(t_package *package, t_visu *visu,
											t_visu_carriagess *struct_carriages)
{
	int				id_carriage;
	int				amount_carriages;
	unsigned char	*content;
	int				color_pair_txt;

	content = package->content;
	ft_memcpy(&id_carriage, content, 4);
	content += 4;
	ft_memcpy(&amount_carriages, content, 4);
	add_function(visu, &color_pair_txt, id_carriage);
	wattrset(visu->w_arena, COLOR_PAIR(color_pair_txt));
	mvwprintw(visu->w_arena, struct_carriages->carriages[id_carriage]->y,
			struct_carriages->carriages[id_carriage]->x,
						struct_carriages->carriages[id_carriage]->original_str);
	wrefresh(visu->w_arena);
	mvwprintw(visu->w_dashboard, DASHBOARD_PROCESSES_Y, DASHBOARD_PROCESSES_X,
													"%-6d", amount_carriages);
	wrefresh(visu->w_dashboard);
	struct_carriages->amount = amount_carriages;
}
