/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:34:30 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 18:22:55 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_run(t_corewar *m_corewar)
{
	if (g_options & O_SERVER)
		corewar_server_mode(m_corewar);
	else if (g_options & O_CLIENT)
		corewar_client_mode(m_corewar);
	else if (g_options & O_VISU)
		corewar_visual_mode(m_corewar);
	else
		corewar_default_mode(m_corewar);
	return (0);
}
