/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_user_verification.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:37:21 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/14 16:34:43 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_boolean	verified(int fd_client)
{
	int				x;

	x = NET_OK;
	if (send(fd_client, &x, 4, 0) < 0)
	{
		perror("Can't verified");
		return (False);
	}
	return (True);
}

t_boolean			network_user_verification(int fd_client, t_connect *connect)
{
	struct pollfd	fds;
	int				ret;
	int				ret_rc;
	char			recv_pass[MAX_LEN_PASS + 2];

	if (!*connect->pass)
		return (verified(fd_client));
	fds.fd = fd_client;
	fds.events = POLLIN;
	ret = poll(&fds, 1, 1000);
	if (ret == -1)
		perror("Verification select");
	else if (ret)
	{
		ft_bzero(recv_pass, MAX_LEN_PASS + 2);
		ret_rc = recv(fd_client, recv_pass, MAX_LEN_PASS + 1, 0);
		ret_rc >= 0 ? recv_pass[ret_rc] = '\0' : 0;
		if (ret_rc < 0)
			perror("Received pass");
		else if (!ft_strcmp(connect->pass, recv_pass))
			return (verified(fd_client));
	}
	return (False);
}
