/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_init_iterator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:36:54 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/03 13:03:22 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriages_init_iterator(t_carriages *i_crrs, t_itercarr *m_iterator)
{
	ft_bzero(m_iterator, sizeof(t_itercarr));
	if (i_crrs->amount > 0)
	{
		m_iterator->current_lst = i_crrs->carriages;
		m_iterator->carriage = m_iterator->current_lst->carriage;
		m_iterator->have_carriage = True;
	}
}
