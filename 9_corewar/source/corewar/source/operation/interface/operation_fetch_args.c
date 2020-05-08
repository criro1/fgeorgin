/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fetch_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:07:53 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/13 13:43:31 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	operation_fetch_args(t_memory *i_mem, int i_addr, t_code *m_code)
{
	t_args arg;

	arg = first_arg;
	while (arg < (t_args)g_op_tab[m_code->oper].num_args && m_code->valid)
	{
		memory_read(i_mem, i_addr, &(m_code->args[arg]),
											m_code->arg_type[size_arg][arg]);
		if (m_code->arg_type[size_arg][arg] == 2)
			m_code->args[arg] = (short)m_code->args[arg];
		if (m_code->arg_type[flag_type][arg] & T_REG)
		{
			if (m_code->args[arg] < MIN_REG || m_code->args[arg] > REG_NUMBER)
				m_code->valid = False;
		}
		i_addr += m_code->arg_type[size_arg][arg];
		++arg;
	}
}
