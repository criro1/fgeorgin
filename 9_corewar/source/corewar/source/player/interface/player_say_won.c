/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_say_won.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:02:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/24 17:06:52 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	player_say_won(t_player *i_player)
{
	ft_printf("Contestant %d, ", i_player->order);
	ft_printf("\"%s\", has won !\n", i_player->name);
}
