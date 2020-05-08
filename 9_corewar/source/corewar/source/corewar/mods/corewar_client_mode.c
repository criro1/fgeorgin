/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_client_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:30:10 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 19:50:04 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <sys/wait.h>

static void			client_relaying(t_connect *m_connect, int fd_out)
{
	struct pollfd	fds;
	t_buff			buff;

	fds.fd = m_connect->sockfd;
	fds.events = POLLIN;
	fds.revents = 0;
	ft_bzero(&buff, sizeof(t_buff));
	network_fetch_data_to_buff(&buff, &fds);
	write(fd_out, buff.data, buff.size_data);
}

static void			corewar_run_client(t_corewar *m_corewar, t_connect *connect,
																	int fd_out)
{
	if (m_corewar && connect)
	{
		network_send_player(connect, players_get_player(m_corewar->players, 1));
		client_relaying(connect, fd_out);
	}
	if (connect)
		connect_destroy(&connect);
}

static t_connect	*network_try_connect(t_corewar *m_corewar)
{
	t_client		*client;
	t_connect		*connect;

	connect = NULL;
	if ((client = get_option_obj(m_corewar->options, "c")))
		connect = network_connect_to_server(client);
	ft_memdel((void*)&client);
	return (connect);
}

void				corewar_client_mode(t_corewar *m_corewar)
{
	pid_t			pid;
	t_connect		*connect;
	int				fds[2];

	if ((connect = network_try_connect(m_corewar)))
	{
		pipe(fds);
		pid = fork();
		if (pid)
		{
			close(fds[0]);
			corewar_run_client(m_corewar, connect, fds[1]);
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
}
