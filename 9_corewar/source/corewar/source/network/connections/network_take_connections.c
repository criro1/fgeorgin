/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_take_connections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:04:06 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/21 22:11:16 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	network_add_new_client(int fd, char *i_h, t_connect *m_conn)
{
	if (network_user_verification(fd, m_conn))
	{
		m_conn->connectfd[m_conn->connect_players] = fd;
		m_conn->connect_players += 1;
	}
	else
	{
		close(fd);
		i_h = NULL;
		ft_memdel((void**)i_h);
	}
}

static inline void	network_handling_new_client(t_connect *connect,
											void *i_their_addr, int client_fd)
{
	char						host_name[INET_ADDRSTRLEN + 1];
	struct sockaddr_storage		*their_addr;

	their_addr = i_their_addr;
	if (client_fd < 0)
		perror("Accept");
	else
	{
		ft_bzero(host_name, sizeof(host_name));
		inet_ntop(their_addr->ss_family,
				&((struct sockaddr_in*)their_addr)->sin_addr,
					host_name, sizeof(host_name));
		network_add_new_client(client_fd, host_name, connect);
		if (connect->connect_players == connect->max_players)
			connect->connect = False;
	}
}

void				*network_take_connections(void *m_connect)
{
	int							new_fd;
	t_connect					*connect;
	socklen_t					sin_size;
	struct sockaddr_storage		their_addr;

	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	connect = m_connect;
	while (connect->connect)
	{
		sin_size = sizeof(their_addr);
		new_fd = accept(connect->sockfd,
				(struct sockaddr *)&their_addr, &sin_size);
		network_handling_new_client(connect, &their_addr, new_fd);
	}
	pthread_exit(0);
}
