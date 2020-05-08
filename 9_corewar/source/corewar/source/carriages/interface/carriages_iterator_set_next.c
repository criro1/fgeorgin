/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_iterator_set_next.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:50:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/20 13:57:48 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriages_iterator_set_next(t_itercarr *m_iterator)
{
	if (m_iterator)
	{
		if (m_iterator->next_lst)
		{
			m_iterator->current_lst = m_iterator->next_lst;
			m_iterator->next_lst = m_iterator->current_lst->next;
			m_iterator->prev_lst = m_iterator->current_lst->prev;
			m_iterator->carriage = m_iterator->current_lst->carriage;
			m_iterator->have_carriage = True;
		}
		else
		{
			m_iterator->have_carriage = False;
			m_iterator->carriage = NULL;
		}
	}
	else
		save_error_to_log("Carriages iterator ", "Not init, can't set next ");
}
