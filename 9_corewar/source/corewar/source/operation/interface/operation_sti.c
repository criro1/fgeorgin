/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:17:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 04:46:29 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_sti(t_carriage *m_carrige, t_code *i_code, t_corewar *m_cor)
{
	int		content_arg[3];
	int		address_to_write;

	ft_bzero(content_arg, sizeof(int) * 3);
	content_arg[0] = carriage_get_reg(m_carrige, i_code->args[arg1]);
	if (i_code->arg_type[flag_type][arg2] & T_REG)
		content_arg[1] = carriage_get_reg(m_carrige, i_code->args[arg2]);
	else if (i_code->arg_type[flag_type][arg2] & T_DIR)
		content_arg[1] = i_code->args[arg2];
	else if (i_code->arg_type[flag_type][arg2] & T_IND)
		memory_read(m_cor->memory,
				memory_shift(m_carrige->address, i_code->args[arg2] % IDX_MOD),
													&content_arg[1], REG_SIZE);
	if (i_code->arg_type[flag_type][arg3] & T_REG)
		content_arg[2] = carriage_get_reg(m_carrige, i_code->args[arg3]);
	else if (i_code->arg_type[flag_type][arg3] & T_DIR)
		content_arg[2] = i_code->args[arg3];
	address_to_write = memory_shift(m_carrige->address,
							(content_arg[1] + content_arg[2]) % IDX_MOD);
	memory_write(m_cor->memory, address_to_write, &content_arg[0], REG_SIZE);
	package_write_in_mem(content_arg[0], address_to_write, m_carrige->id,
																	m_cor->fd);
	return (OPER_SUCCESS);
}
