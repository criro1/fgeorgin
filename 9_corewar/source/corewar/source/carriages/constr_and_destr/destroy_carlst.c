/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_carlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:31:09 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/06 21:37:31 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_carlst(t_carlst **m_lst_for_del)
{
	if (m_lst_for_del && *m_lst_for_del)
	{
		if ((*m_lst_for_del)->carriage)
			destroy_carriage(&(*m_lst_for_del)->carriage);
		ft_memdel((void**)m_lst_for_del);
	}
}
