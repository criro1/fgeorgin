/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 20:22:55 by astamm            #+#    #+#             */
/*   Updated: 2020/04/27 22:33:44 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_visu(t_visu *visu)
{
	int	index_player;
	int	index_cariage;

	delwin(visu->w_arena);
	delwin(visu->w_dashboard);
	delwin(visu->w_info);
	index_player = 0;
	while (index_player < visu->gamers.amount)
	{
		ft_memdel((void**)&visu->gamers.player[index_player].name);
		++index_player;
	}
	pthread_join(visu->thread, NULL);
	ft_memdel((void**)&visu->keyboard);
	ft_memdel((void**)&visu->arena);
	index_cariage = 0;
	while (index_cariage < visu->struct_carriages.amount_maloc_car)
		ft_memdel((void**)&visu->struct_carriages.carriages[index_cariage++]);
	ft_memdel((void**)&visu->struct_carriages.carriages);
	endwin();
}
