/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_default_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:17:32 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 01:41:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar_default_mode(t_corewar *m_corewar)
{
	players_introducing(m_corewar->players);
	corewar_core(m_corewar);
	if (!(g_options & O_DUMP))
		corewar_honoring_the_winner(m_corewar);
}
