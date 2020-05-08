/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_set_address.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:18:35 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 19:44:25 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriage_set_address(t_carriage *m_carriage, int i_address)
{
	if (i_address < MEM_SIZE)
	{
		if (i_address < 0)
			m_carriage->address = MEM_SIZE + i_address;
		else
			m_carriage->address = i_address;
	}
	else
		m_carriage->address = i_address % MEM_SIZE;
}
