/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:15:59 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/23 11:01:35 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_player(t_player **m_player)
{
	if (m_player && *m_player)
	{
		destroy_file(&(*m_player)->file);
		ft_memdel((void**)&(*m_player)->name);
		ft_memdel((void**)&(*m_player)->comment);
		ft_bzero((*m_player)->mem_champion, CHAMP_MAX_SIZE);
		ft_memdel((void**)m_player);
	}
}
