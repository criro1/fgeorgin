/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_server_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:15:51 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 18:57:23 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <sys/types.h>
#include <sys/wait.h>

static void	corewar_fight(t_corewar *m_corewar, int fd_broadcast)
{
	m_corewar->fd = fd_broadcast;
	packages_init_corewar(m_corewar);
	package_end_init(m_corewar->fd);
	corewar_core(m_corewar);
	package_end_game(m_corewar->fd);
}

static void	corewar_run_server(t_corewar *m_corewar, int fd_out)
{
	t_server	*server;
	t_connect	*connect;
	int			fds[2];

	pipe(fds);
	connect = NULL;
	server = get_option_obj(m_corewar->options, "s");
	server->fd_in = fds[0];
	server->fd_out = fd_out;
	if (server && (connect = network_get_connect_clients(server,
														m_corewar->players)))
	{
		if ((m_corewar = corewar_resolve(m_corewar)) && !errno)
			corewar_fight(m_corewar, fds[1]);
		if (errno)
			perror("Fight crash");
		connect_destroy(&connect);
	}
	close(fds[1]);
	close(fds[0]);
	ft_memdel((void*)&server);
}

void		corewar_server_mode(t_corewar *m_corewar)
{
	pid_t	pid;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid)
	{
		close(fds[0]);
		corewar_run_server(m_corewar, fds[1]);
		wait(NULL);
		close(fds[1]);
	}
	else
	{
		close(fds[1]);
		visu_run(fds[0]);
		close(fds[0]);
	}
}
