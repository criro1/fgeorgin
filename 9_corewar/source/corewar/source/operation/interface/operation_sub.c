/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:06:18 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/21 22:06:26 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_sub(t_carriage *m_cr, t_code *i_cod, t_corewar *m_cor)
{
	t_reg	result;

	m_cor->players->amount += 0;
	result = carriage_get_reg(m_cr, i_cod->args[arg1]) -
									carriage_get_reg(m_cr, i_cod->args[arg2]);
	carriage_set_carry(m_cr, (result ? False : True));
	carriage_set_reg(m_cr, i_cod->args[arg3], result);
	return (OPER_SUCCESS);
}
