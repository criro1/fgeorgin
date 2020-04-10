/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_valid_code_oper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:22:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/03 17:40:47 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	operation_valid_code_oper(int i_code)
{
	if (i_code >= op_tab[first_oper].code && i_code <= op_tab[last_oper].code)
		return (True);
	return (False);
}
