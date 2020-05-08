/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_options_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:14:50 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/23 11:10:32 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_options_list(t_options_list **m_list)
{
	if (m_list && *m_list)
	{
		ft_memdel((void**)&(*m_list)->option_obj);
		ft_memdel((void**)&(*m_list)->name);
		ft_memdel((void**)m_list);
	}
}
