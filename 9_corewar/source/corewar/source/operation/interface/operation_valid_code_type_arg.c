/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_valid_code_type_arg.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:52:01 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/06 13:22:11 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	operation_valid_code_type_arg(t_code *m_code)
{
	t_args	arg;
	t_oper	oper;

	arg = first_arg;
	oper = m_code->oper;
	while (arg < (t_args)g_op_tab[oper].num_args)
	{
		if (!(m_code->arg_type[flag_type][arg] & g_op_tab[oper].type[arg]))
		{
			m_code->valid = False;
			return (False);
		}
		++arg;
	}
	m_code->valid = True;
	return (True);
}
