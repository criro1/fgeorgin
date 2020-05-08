/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_lfork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:58:43 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 10:19:55 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			operation_lfork(t_carriage *m_ca, t_code *i_cod, t_corewar *m_c)
{
	t_carriage	*clone;

	if ((clone = carriage_clone(m_ca)))
	{
		carriage_set_address(clone, m_ca->address + i_cod->args[arg1]);
		if (!carriages_add_carige(m_c->carriages, clone))
		{
			save_error_to_log("Operations lfork", "Can't add to carriages");
			return (OPER_ERROR);
		}
	}
	else
	{
		save_error_to_log("Operations lfork", E_NO_MEM);
		return (OPER_ERROR);
	}
	send_package_new_carriage(clone, m_ca->id, m_c->carriages->amount, m_c->fd);
	return (OPER_SUCCESS);
}
