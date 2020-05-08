/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_carriages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:47:55 by astamm            #+#    #+#             */
/*   Updated: 2020/03/16 18:23:40 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_color_carriages(t_visu *visu)
{
	int index;

	index = 0;
	while (index < visu->gamers.amount && index < visu->struct_carriages.amount)
	{
		visu->struct_carriages.carriages[index]->color_pair_player =
										visu->gamers.player[index].color_pair;
		index++;
	}
}
