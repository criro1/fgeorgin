/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_delete_carrige.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:25:24 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/20 14:00:29 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriages_delete_carrige(t_itercarr *m_iterator)
{
	if (m_iterator && m_iterator->carriage && m_iterator->current_lst)
	{
		m_iterator->have_carriage = False;
		if (m_iterator->next_lst)
			m_iterator->next_lst->prev = m_iterator->current_lst->prev;
		if (m_iterator->prev_lst)
			m_iterator->prev_lst->next = m_iterator->current_lst->next;
		if (m_iterator->current_lst == *m_iterator->head_lst)
			*m_iterator->head_lst = m_iterator->current_lst->next;
		m_iterator->carriage = NULL;
		destroy_carlst(&m_iterator->current_lst);
		--(*(m_iterator->amount_carriages));
	}
}
