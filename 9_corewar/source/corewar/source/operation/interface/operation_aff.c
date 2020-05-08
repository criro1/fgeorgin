/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:47:30 by astamm            #+#    #+#             */
/*   Updated: 2020/04/22 20:05:10 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		operation_aff(t_carriage *m_carr, t_code *i_code, t_corewar *m_cor)
{
	m_cor->players->amount += 0;
	if (g_options & O_AFF)
		ft_printf("Aff: %c\n",
				(char)carriage_get_reg(m_carr, i_code->args[arg1]));
	return (OPER_SUCCESS);
}
