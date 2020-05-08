/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_resolve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:14:25 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 16:05:11 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	corewar_memdel(t_corewar *d_corewar)
{
	destroy_memory(&(d_corewar->memory));
	destroy_params(&(d_corewar->params));
	destroy_carriages(&(d_corewar->carriages));
	carriages_add_carige(NULL, NULL);
}

t_corewar	*corewar_resolve(t_corewar *m_corewar)
{
	corewar_memdel(m_corewar);
	if (init_players(m_corewar->players))
		m_corewar->memory = new_memory(m_corewar->players);
	if (!errno)
		m_corewar->params = new_params(m_corewar->players);
	if (!errno)
		m_corewar->carriages = new_carriages(m_corewar->memory);
	if (errno)
	{
		perror("Corewar can't resolve");
		return (NULL);
	}
	return (m_corewar);
}
