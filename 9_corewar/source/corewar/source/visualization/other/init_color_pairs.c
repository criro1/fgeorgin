/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_pairs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:09:08 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 11:40:21 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_color_pairs(void)
{
	start_color();
	init_pair(1, COLOR_MAGENTA, 0);
	init_pair(2, COLOR_CYAN, 0);
	init_pair(3, COLOR_RED, 0);
	init_pair(4, COLOR_YELLOW, 0);
	init_pair(5, COLOR_GREEN, 0);
	init_pair(6, 27, 0);
	init_pair(COLOR_PAIR_GRAY_VISU, COLOR_WHITE, 0);
	init_pair(8, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(9, COLOR_WHITE, COLOR_CYAN);
	init_pair(10, COLOR_WHITE, COLOR_RED);
	init_pair(11, COLOR_WHITE, COLOR_YELLOW);
	init_pair(12, COLOR_WHITE, COLOR_GREEN);
	init_pair(13, COLOR_WHITE, 27);
	init_pair(14, COLOR_BLACK, COLOR_WHITE);
	init_pair(COLOR_PAIR_WHITE_VISU, 255, 0);
}
