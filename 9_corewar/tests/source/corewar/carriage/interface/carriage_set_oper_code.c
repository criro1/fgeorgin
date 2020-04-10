/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_set_oper_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:12:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/03 19:57:50 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriage_set_oper_code(t_carriage *m_carriage, t_memory *i_memory)
{
	memory_read(i_memory, m_carriage->address, &m_carriage->code, 1);
	if (operation_valid_code_oper(m_carriage->code))
		m_carriage->cycle_to_exec = operation_get_cyle_exec(m_carriage->code);
}
