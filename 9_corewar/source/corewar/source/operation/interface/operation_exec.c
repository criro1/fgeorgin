/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:56:44 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 00:35:06 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	operation_exec(t_carriage *m_carriage, t_corewar *m_corewar)
{
	t_code	code;

	--m_carriage->cycle_to_exec;
	if (m_carriage->cycle_to_exec <= 0)
	{
		code = carriage_fetch_code(m_carriage, m_corewar->memory);
		if (code.valid)
		{
			g_op_tab[code.oper].exec(m_carriage, &code, m_corewar);
			m_carriage->cycle_to_exec = 0;
		}
		if (code.oper != zjmp_op)
		{
			carriage_skip_code(m_carriage, &code);
			package_change_carriage_address(m_carriage->id, m_carriage->address,
																m_corewar->fd);
		}
	}
}
