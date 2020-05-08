/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_decrease_ctd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:24:02 by astamm            #+#    #+#             */
/*   Updated: 2020/03/15 17:51:33 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visu_decrease_ctd(t_package *package, t_visu *visu)
{
	int				cycle_to_die;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&cycle_to_die, content, 4);
	mvwprintw(visu->w_dashboard, DASHBOARD_CTD_Y, DASHBOARD_CTD_X, "%-7d",
																cycle_to_die);
	wrefresh(visu->w_dashboard);
}
