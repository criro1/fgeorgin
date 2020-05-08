/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:39:13 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/21 22:05:31 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			operation_add(t_carriage *m_cr, t_code *i_cod, t_corewar *m_cor)
{
	t_reg	result;

	m_cor->players->amount += 0;
	result = carriage_get_reg(m_cr, i_cod->args[arg1]) +
									carriage_get_reg(m_cr, i_cod->args[arg2]);
	carriage_set_carry(m_cr, (result ? False : True));
	carriage_set_reg(m_cr, i_cod->args[arg3], result);
	return (OPER_SUCCESS);
}
