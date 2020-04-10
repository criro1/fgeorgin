/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:59:35 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/31 16:50:10 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	player_memcpy(t_player *i_pl, void *m_dst)
{
	if (i_pl && m_dst)
		ft_memcpy(m_dst, i_pl->mem_champion, player_get_size(i_pl));
	else
		save_error_to_log("Player ", "Can't copy memory (input = NULL) ");
}
