/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_args_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:02:13 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/23 11:33:05 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_args_obj(t_args_obj **m_args)
{
	if (m_args && *m_args)
	{
		destroy_options(&(*m_args)->options);
		destroy_players(&(*m_args)->players);
		ft_memdel((void**)m_args);
	}
}
