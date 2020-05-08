/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:25:33 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 04:50:23 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_st(t_carriage *m_cr, t_code *i_cod, t_corewar *m_cor)
{
	int		data_from_reg;
	int		addres_to_write;

	data_from_reg = carriage_get_reg(m_cr, i_cod->args[arg1]);
	if (i_cod->arg_type[flag_type][arg2] & T_REG)
		carriage_set_reg(m_cr, i_cod->args[arg2], data_from_reg);
	else if (i_cod->arg_type[flag_type][arg2] & T_IND)
	{
		addres_to_write = memory_shift(m_cr->address,
												i_cod->args[arg2] % IDX_MOD);
		memory_write(m_cor->memory, addres_to_write, &data_from_reg, REG_SIZE);
		package_write_in_mem(data_from_reg, addres_to_write, m_cr->id,
																	m_cor->fd);
	}
	return (OPER_SUCCESS);
}
