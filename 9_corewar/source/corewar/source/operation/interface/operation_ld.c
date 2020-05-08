/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:29:26 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 00:58:11 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_ld(t_carriage *m_carriage, t_code *i_code, t_corewar *m_cor)
{
	int			data_to_reg;

	data_to_reg = 0;
	if (i_code->arg_type[flag_type][arg1] & T_DIR)
		data_to_reg = i_code->args[arg1];
	else if (i_code->arg_type[flag_type][arg1] & T_IND)
		memory_read(m_cor->memory,
				memory_shift(m_carriage->address, i_code->args[arg1] % IDX_MOD),
					&data_to_reg, REG_SIZE);
	carriage_set_carry(m_carriage, (data_to_reg ? False : True));
	carriage_set_reg(m_carriage, i_code->args[arg2], data_to_reg);
	return (OPER_SUCCESS);
}
