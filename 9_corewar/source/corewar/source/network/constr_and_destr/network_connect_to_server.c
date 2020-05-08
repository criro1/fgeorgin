/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_connect_to_server.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:39:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/14 20:47:11 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	network_wait_connections(int sockfd, struct addrinfo *servinfo)
{
	struct pollfd	fds;
	int				options;
	int				res;

	options = 0;
	if ((options = fcntl(sockfd, F_GETFL, NULL) < 0))
		return (-1);
	if ((options = fcntl(sockfd, F_SETFL, options | O_NONBLOCK) < 0))
		return (-1);
	if ((res = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) < 0))
	{
		if (errno == EINPROGRESS)
		{
			fds.fd = sockfd;
			fds.events = POLLOUT;
			fds.revents = 0;
			res = poll(&fds, 1, 5000);
		}
	}
	else
		res = 1;
	if ((options = fcntl(sockfd, F_SETFL, options)) < 0)
		return (-1);
	errno = (res == 0 ? ETIMEDOUT : 0);
	return (res);
}

static int	network_get_socket(t_client *i_client)
{
	int				o_sockfd;
	char			*port;
	struct addrinfo	*servinfo;

	port = (*i_client->port ? i_client->port : STANDART_PORT);
	if (!(servinfo = network_get_servinfo(i_client->ip_server, port)))
		return (-1);
	if ((o_sockfd = socket(servinfo->ai_family, servinfo->ai_socktype,
					servinfo->ai_protocol)) < 0)
	{
		perror("Socket");
		freeaddrinfo(servinfo);
		return (-1);
	}
	if (network_wait_connections(o_sockfd, servinfo) < 0)
	{
		perror("Connect");
		freeaddrinfo(servinfo);
		return (-1);
	}
	freeaddrinfo(servinfo);
	return (o_sockfd);
}

t_connect	*network_connect_to_server(t_client *i_client)
{
	t_connect		*o_new;

	if ((o_new = (t_connect *)ft_memalloc(sizeof(t_connect))))
	{
		o_new->sockfd = network_get_socket(i_client);
		if (!errno && !network_verification(i_client->pass, o_new->sockfd))
			errno = EACCES;
	}
	if (errno)
	{
		ft_memdel((void**)&o_new);
		perror("Can't create connect to server");
	}
	return (o_new);
}
