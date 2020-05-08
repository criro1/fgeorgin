/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_package_new_carriage.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:25:53 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 11:47:41 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	print_processes(int amount, WINDOW *w_dashboard)
{
	mvwprintw(w_dashboard, DASHBOARD_PROCESSES_Y,
										DASHBOARD_PROCESSES_X, "%-6d", amount);
	wrefresh(w_dashboard);
}

static inline void	realloc_mem_carriages(t_visu_carriagess *struct_carriages)
{
	struct_carriages->memory_allocated += sizeof(t_visu_carriage*)
														* AND_MEM_CARRIAGES;
	struct_carriages->carriages = realloc(struct_carriages->carriages,
										struct_carriages->memory_allocated);
	struct_carriages->amount_maloc_car += AND_MEM_CARRIAGES;
}

void				accept_package_new_carriage(t_package *package,
							t_visu_carriagess *struct_carriages, t_visu *visu)
{
	int				id;
	int				id_parent;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&id, content, 4);
	content += 4;
	if (id >= struct_carriages->amount_maloc_car)
		realloc_mem_carriages(struct_carriages);
	struct_carriages->carriages[id] = ft_memalloc(sizeof(t_visu_carriage));
	struct_carriages->carriages[id]->id = id;
	ft_memcpy(&struct_carriages->carriages[id]->address, content, 4);
	content += 4;
	ft_memcpy(&id_parent, content, 4);
	struct_carriages->carriages[id]->color_pair_player =
					struct_carriages->carriages[id_parent]->color_pair_player;
	content += 4;
	ft_memcpy(&struct_carriages->amount, content, 4);
	print_processes(struct_carriages->amount, visu->w_dashboard);
	visu_new_carriage(visu, struct_carriages->carriages[id]);
}
