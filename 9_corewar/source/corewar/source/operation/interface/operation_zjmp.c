/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_zjmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:42:55 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/13 20:56:34 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_zjmp(t_carriage *m_carriage, t_code *i_code, t_corewar *m_cor)
{
	if (m_carriage->carry)
	{
		carriage_set_address(m_carriage,
			memory_shift(m_carriage->address, i_code->args[arg1] % IDX_MOD));
		package_change_carriage_address(m_carriage->id, m_carriage->address,
																	m_cor->fd);
	}
	else
	{
		carriage_skip_code(m_carriage, i_code);
		package_change_carriage_address(m_carriage->id, m_carriage->address,
																	m_cor->fd);
	}
	return (OPER_SUCCESS);
}
