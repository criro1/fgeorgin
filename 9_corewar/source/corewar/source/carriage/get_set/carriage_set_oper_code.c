/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_set_oper_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:12:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/13 11:37:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriage_set_oper_code(t_carriage *m_carriage, t_memory *i_mem)
{
	m_carriage->code = 0;
	memory_read(i_mem, m_carriage->address, &m_carriage->code, SIZE_OPER_CODE);
	if (operation_valid_code_oper(m_carriage->code))
		m_carriage->cycle_to_exec = operation_get_cyle_exec(m_carriage->code);
}
