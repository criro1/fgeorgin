/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_add_carige.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:12:02 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 16:03:18 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_carlst	*carriages_new_carlst(t_carriage *i_carr)
{
	t_carlst	*o_new;

	if ((o_new = (t_carlst *)ft_memalloc(sizeof(t_carlst))))
		o_new->carriage = i_carr;
	else
		save_error_to_log("Carriages ", " Can't create list ");
	return (o_new);
}

static void		carriages_push_to_lists(t_carriages *m_crs, t_carlst *m_list)
{
	if (m_crs->carriages)
	{
		m_list->next = m_crs->carriages;
		m_crs->carriages->prev = m_list;
	}
	m_crs->carriages = m_list;
	++m_crs->amount;
}

t_boolean		carriages_add_carige(t_carriages *m_carrs, t_carriage *m_carr)
{
	static int	id;
	t_carlst	*new;

	if (m_carr)
	{
		if (!(new = carriages_new_carlst(m_carr)))
			return (False);
		carriage_set_id(m_carr, id++);
		carriages_push_to_lists(m_carrs, new);
	}
	else if (!m_carr)
		id = 0;
	else
		save_error_to_log("Carriages ", "Attempt to add NULL ");
	return (True);
}
