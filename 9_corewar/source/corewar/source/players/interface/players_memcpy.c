/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:48:37 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/31 17:55:02 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	players_memcpy(t_players *i_pls, int i_order, void *m_dst)
{
	if (i_order > 0 && i_order <= players_get_amount(i_pls))
		player_memcpy(i_pls->player[i_order - 1], m_dst);
	else
		save_error_to_log("Players ", "Error memcpy invalid oreder ");
}
