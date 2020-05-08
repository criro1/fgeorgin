/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carriage_for_visu.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:57:09 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 15:52:41 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	realloc_mem_carriages(t_visu_carriagess *struct_carriages)
{
	struct_carriages->memory_allocated += sizeof(t_visu_carriage*)
														* AND_MEM_CARRIAGES;
	struct_carriages->carriages = realloc(struct_carriages->carriages,
										struct_carriages->memory_allocated);
	struct_carriages->amount_maloc_car += AND_MEM_CARRIAGES;
}

void				init_carriage_for_visu(t_package *package,
					t_visu_carriagess *struct_carriages, WINDOW *w_dashboard)
{
	int				id;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&id, content, 4);
	content += 4;
	if (id >= struct_carriages->amount_maloc_car)
		realloc_mem_carriages(struct_carriages);
	struct_carriages->carriages[id] = ft_memalloc(sizeof(t_visu_carriage));
	struct_carriages->carriages[id]->id = id;
	ft_memcpy(&struct_carriages->carriages[id]->address, content, 4);
	if (struct_carriages->amount < id + 1)
	{
		struct_carriages->amount = id + 1;
		mvwprintw(w_dashboard, DASHBOARD_PROCESSES_Y,
										DASHBOARD_PROCESSES_X, "%-6d", id + 1);
		wrefresh(w_dashboard);
	}
	ft_memdel((void**)&package->content);
}
