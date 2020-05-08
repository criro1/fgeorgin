/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:26:39 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:07:32 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_xor(t_carriage *m_carrige, t_code *i_code, t_corewar *m_cor)
{
	int		data[3];

	ft_bzero(data, sizeof(int) * 3);
	if (i_code->arg_type[flag_type][arg1] & T_REG)
		data[0] = carriage_get_reg(m_carrige, i_code->args[arg1]);
	else if (i_code->arg_type[flag_type][arg1] & T_DIR)
		data[0] = i_code->args[arg1];
	else if (i_code->arg_type[flag_type][arg1] & T_IND)
		memory_read(m_cor->memory, memory_shift(m_carrige->address,
					i_code->args[arg1] % IDX_MOD), &data[0], REG_SIZE);
	if (i_code->arg_type[flag_type][arg2] & T_REG)
		data[1] = carriage_get_reg(m_carrige, i_code->args[arg2]);
	else if (i_code->arg_type[flag_type][arg2] & T_DIR)
		data[1] = i_code->args[arg2];
	else if (i_code->arg_type[flag_type][arg2] & T_IND)
		memory_read(m_cor->memory, memory_shift(m_carrige->address,
					i_code->args[arg2] % IDX_MOD), &data[1], REG_SIZE);
	data[2] = data[0] ^ data[1];
	carriage_set_carry(m_carrige, (data[2] ? False : True));
	carriage_set_reg(m_carrige, i_code->args[arg3], data[2]);
	return (OPER_SUCCESS);
}
