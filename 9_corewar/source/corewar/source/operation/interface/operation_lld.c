/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_lld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:11:48 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 01:18:27 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_lld(t_carriage *m_carriage, t_code *i_code, t_corewar *m_cor)
{
	int			data_to_reg;
	short		data_to_reg2;

	data_to_reg = 0;
	data_to_reg2 = 0;
	if (i_code->arg_type[flag_type][arg1] & T_DIR)
		data_to_reg = i_code->args[arg1];
	else if (i_code->arg_type[flag_type][arg1] & T_IND)
		memory_read(m_cor->memory,
				memory_shift(m_carriage->address, i_code->args[arg1]),
					&data_to_reg2, 2);
	data_to_reg = (data_to_reg2 ? data_to_reg2 : data_to_reg);
	carriage_set_carry(m_carriage, (data_to_reg ? False : True));
	carriage_set_reg(m_carriage, i_code->args[arg2], data_to_reg);
	return (OPER_SUCCESS);
}
