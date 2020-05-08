/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:40:48 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 19:31:08 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar_exec(t_corewar *m_corewar)
{
	t_itercarr	carriter;

	carriages_init_iterator(m_corewar->carriages, &carriter);
	while (carriter.have_carriage)
	{
		if (carriage_need_set_code(carriter.carriage))
			carriage_set_oper_code(carriter.carriage, m_corewar->memory);
		operation_exec(carriter.carriage, m_corewar);
		carriages_iterator_set_next(&carriter);
	}
}
