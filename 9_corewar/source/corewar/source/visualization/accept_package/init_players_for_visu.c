/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players_for_visu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:58:26 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 15:52:27 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_players_for_visu(t_package *package, t_visu *visu)
{
	int				number_player;
	int				size_name;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&number_player, content, 4);
	visu->gamers.player[number_player - 1].number = number_player;
	content += 4;
	visu->gamers.amount = number_player;
	ft_memcpy(&visu->gamers.player[number_player - 1].code_size_player,
																	content, 4);
	content += 4;
	ft_memcpy(&size_name, content, 4);
	content += 4;
	visu->gamers.player[number_player - 1].name = ft_memalloc(size_name + 1);
	ft_memcpy(visu->gamers.player[number_player - 1].name, content, size_name);
	ft_memdel((void**)&package->content);
}
