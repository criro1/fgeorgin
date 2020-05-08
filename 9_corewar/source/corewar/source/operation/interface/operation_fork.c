/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:32:36 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 10:17:15 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			operation_fork(t_carriage *m_ca, t_code *i_cod, t_corewar *m_c)
{
	t_carriage	*clone;

	if ((clone = carriage_clone(m_ca)))
	{
		carriage_set_address(clone, memory_shift(m_ca->address,
												i_cod->args[arg1] % IDX_MOD));
		if (!carriages_add_carige(m_c->carriages, clone))
		{
			save_error_to_log("Operations fork", "Can't add to carriages");
			return (OPER_ERROR);
		}
	}
	else
	{
		save_error_to_log("Operations fork", E_NO_MEM);
		return (OPER_ERROR);
	}
	send_package_new_carriage(clone, m_ca->id, m_c->carriages->amount, m_c->fd);
	return (OPER_SUCCESS);
}
