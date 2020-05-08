/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_verification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:42:26 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:47:43 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	exchange_password(char *i_pass, int i_fd_server)
{
	struct pollfd	fds;
	int				token;
	int				ret_poll;

	if (*i_pass && send(i_fd_server, i_pass, ft_strlen(i_pass), 0) < 0)
		return (-1);
	fds.fd = i_fd_server;
	fds.events = POLLIN;
	ret_poll = poll(&fds, 1, 1000);
	token = 0;
	if (ret_poll < 0)
		return (-1);
	else if (ret_poll)
	{
		if (recv(i_fd_server, &token, 4, 0) < 0)
			return (-1);
		if (token == NET_OK)
			return (1);
		else
			errno = EACCES;
	}
	return (0);
}

int			network_verification(char *i_pass, int i_fd_server)
{
	int		ret_serv;

	if (i_pass)
	{
		if ((ret_serv = exchange_password(i_pass, i_fd_server)) < 0)
		{
			perror("Can't verification");
			return (-1);
		}
		else if (ret_serv)
			return (1);
	}
	return (0);
}
