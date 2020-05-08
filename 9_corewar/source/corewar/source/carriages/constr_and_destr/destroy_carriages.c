/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_carriages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:39:40 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 14:36:38 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriages_destroy_carlst(t_carlst **m_lst)
{
	if (m_lst && *m_lst)
	{
		carriages_destroy_carlst(&(*m_lst)->next);
		destroy_carriage(&(*m_lst)->carriage);
		ft_memdel((void**)m_lst);
	}
}

void	destroy_carriages(t_carriages **m_carriages)
{
	if (m_carriages && *m_carriages)
	{
		carriages_destroy_carlst(&(*m_carriages)->carriages);
		(*m_carriages)->amount = 0;
		ft_memdel((void**)m_carriages);
	}
}
