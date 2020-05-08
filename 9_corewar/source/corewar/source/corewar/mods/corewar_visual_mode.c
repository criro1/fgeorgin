/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visual_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 05:42:30 by astamm            #+#    #+#             */
/*   Updated: 2020/04/22 19:04:44 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <sys/types.h>
#include <sys/wait.h>

void	corewar_visual_mode(t_corewar *m_corewar)
{
	int	fd_visu[2];
	int	pid;
	int	sign;

	pipe(fd_visu);
	pid = fork();
	if (pid)
	{
		close(fd_visu[0]);
		m_corewar->fd = fd_visu[1];
		packages_init_corewar(m_corewar);
		corewar_core(m_corewar);
		package_winning_player(m_corewar->params->pl_live->order,
															m_corewar->fd);
		package_end_game(m_corewar->fd);
		wait(&sign);
		close(fd_visu[1]);
	}
	else
	{
		close(fd_visu[1]);
		visu_run(fd_visu[0]);
		close(fd_visu[0]);
	}
}
