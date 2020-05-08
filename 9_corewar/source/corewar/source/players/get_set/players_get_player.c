/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_get_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:37:29 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/31 21:48:11 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*players_get_player(t_players *i_pls, int i_order)
{
	if (i_order < 1 || i_order > i_pls->amount)
	{
		save_error_to_log("Players ", "Can't get player (invalid order)");
		return (NULL);
	}
	return (i_pls->player[i_order - 1]);
}
