/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_lldi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:11:43 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 00:58:50 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_lldi(t_carriage *m_carrige, t_code *i_code, t_corewar *m_cor)
{
	int		content_arg[3];

	ft_bzero(content_arg, sizeof(int) * 3);
	if (i_code->arg_type[flag_type][arg1] & T_REG)
		content_arg[0] = carriage_get_reg(m_carrige, i_code->args[arg1]);
	else if (i_code->arg_type[flag_type][arg1] & T_DIR)
		content_arg[0] = i_code->args[arg1];
	else if (i_code->arg_type[flag_type][arg1] & T_IND)
		memory_read(m_cor->memory, memory_shift(m_carrige->address,
				(i_code->args[arg1] % IDX_MOD)), &content_arg[0], REG_SIZE);
	if (i_code->arg_type[flag_type][arg2] & T_REG)
		content_arg[1] = carriage_get_reg(m_carrige, i_code->args[arg2]);
	else if (i_code->arg_type[flag_type][arg2] & T_DIR)
		content_arg[1] = i_code->args[arg2];
	memory_read(m_cor->memory,
			memory_shift(m_carrige->address, content_arg[0] + content_arg[1]),
				&content_arg[2], REG_SIZE);
	carriage_set_carry(m_carrige, (content_arg[2] ? False : True));
	carriage_set_reg(m_carrige, i_code->args[arg3], content_arg[2]);
	return (OPER_SUCCESS);
}
