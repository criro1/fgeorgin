/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_iterator_set_next.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:50:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/03 13:01:42 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriages_iterator_set_next(t_itercarr *m_iterator)
{
	if (!(m_iterator && m_iterator->current_lst))
	{
		if (m_iterator->current_lst->next)
		{
			m_iterator->current_lst = m_iterator->current_lst->next;
			m_iterator->carriage = m_iterator->current_lst->carriage;
			m_iterator->have_carriage = True;
		}
		else
		{
			ft_bzero(m_iterator, sizeof(t_itercarr));
			m_iterator->have_carriage = False;
		}
	}
	else if (!(m_iterator && m_iterator->have_carriage))
		save_error_to_log("Carriages iterator ", "Not init, can't set next ");
}
