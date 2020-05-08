/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_valid_code_oper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:22:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/06 13:15:27 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	operation_valid_code_oper(int i_cod)
{
	if (i_cod >= g_op_tab[first_oper].code && i_cod <= g_op_tab[last_oper].code)
		return (True);
	return (False);
}
