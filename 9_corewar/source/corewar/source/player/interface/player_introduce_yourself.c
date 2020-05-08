/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_introduce_yourself.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:05:54 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/13 11:32:20 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	player_introduce_yourself(t_player *i_player)
{
	ft_printf("* Player %d, ", i_player->order);
	ft_printf("weighing %d bytes, ", i_player->size_bytes);
	ft_printf("\"%s\" (\"%s\") !\n", i_player->name, i_player->comment);
}
