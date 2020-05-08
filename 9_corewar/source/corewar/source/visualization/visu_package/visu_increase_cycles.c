/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_increase_cycles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:14:08 by astamm            #+#    #+#             */
/*   Updated: 2020/03/15 17:51:36 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visu_increase_cycles(t_package *package, t_visu *visu)
{
	long			cycle;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&cycle, content, 8);
	mvwprintw(visu->w_dashboard, DASHBOARD_CYCLE_Y, DASHBOARD_CYCLE_X, "%ld",
																		cycle);
	wrefresh(visu->w_dashboard);
}
