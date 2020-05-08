/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_end_code_players.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:01:12 by astamm            #+#    #+#             */
/*   Updated: 2020/03/11 22:58:41 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_start_end_code_players(t_visu_gamers *gamers,
											t_visu_carriagess *struct_carriages)
{
	int			index;

	index = 0;
	while (index < struct_carriages->amount && index < gamers->amount)
	{
		gamers->player[index].byte_start_code =
									struct_carriages->carriages[index]->address;
		gamers->player[index].byte_end_code =
			gamers->player[index].byte_start_code +
									gamers->player[index].code_size_player - 1;
		index++;
	}
}
