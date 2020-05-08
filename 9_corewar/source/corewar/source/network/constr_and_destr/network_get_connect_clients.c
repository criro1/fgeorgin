/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_get_connect_clients.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:49:38 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/14 21:08:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			network_get_socket(t_server *i_server)
{
	int				o_sockfd;
	int				enabl;
	char			*port;
	struct addrinfo	*servinfo;

	enabl = 1;
	port = (*i_server->port ? i_server->port : STANDART_PORT);
	if (!(servinfo = network_get_servinfo(NULL, port)))
		return (-1);
	if ((o_sockfd = socket(servinfo->ai_family, servinfo->ai_socktype,
					servinfo->ai_protocol)) < 0)
	{
		perror("Socket");
		return (-1);
	}
	if (setsockopt(o_sockfd, SOL_SOCKET, SO_REUSEADDR, &enabl, sizeof(int)) < 0)
		perror("setsockopt(SO_REUSEADDR) failed");
	if (bind(o_sockfd, servinfo->ai_addr, servinfo->ai_addrlen) < 0)
		perror("Bind");
	freeaddrinfo(servinfo);
	if (!errno && listen(o_sockfd, NET_BACKLOG) < 0)
		perror("Listen");
	return (o_sockfd);
}

static inline void	network_run_connections(t_connect *m_cnn)
{
	pthread_create(&(m_cnn->thread[0]), NULL, network_take_connections, m_cnn);
	pthread_create(&(m_cnn->thread[1]), NULL, network_stop_conections, m_cnn);
	pthread_create(&(m_cnn->thread[2]), NULL, network_recv_players, m_cnn);
	pthread_create(&(m_cnn->thread[3]), NULL, network_broadcast, m_cnn);
}

static inline void	network_wait_join(t_connect *m_connect)
{
	pthread_join((m_connect->thread)[0], NULL);
	pthread_join((m_connect->thread)[1], NULL);
	pthread_join((m_connect->thread)[2], NULL);
	m_connect->connect = False;
	errno = 0;
}

static void			connection_del_mem(t_connect **del_connect)
{
	ft_memdel((void**)del_connect);
}

t_connect			*network_get_connect_clients(t_server *i_serv,
																t_players *pls)
{
	t_connect		*o_new;

	if (pls && (o_new = (t_connect *)ft_memalloc(sizeof(t_connect))))
	{
		o_new->connect = True;
		o_new->players = pls;
		o_new->sockfd = network_get_socket(i_serv);
		if (!errno)
		{
			o_new->max_players = (i_serv->amount_players ?
				i_serv->amount_players : MAX_PLAYERS) - o_new->players->amount;
			ft_memcpy(o_new->pass, i_serv->pass, MAX_LEN_PASS);
			o_new->in_fds.fd = i_serv->fd_in;
			o_new->in_fds.events = POLLIN;
			o_new->out_fd = i_serv->fd_out;
			network_run_connections(o_new);
			network_wait_join(o_new);
		}
	}
	if (errno)
		connection_del_mem(&o_new);
	return (o_new);
}
