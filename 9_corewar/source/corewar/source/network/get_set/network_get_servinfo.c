/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_get_servinfo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:26:33 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 13:30:24 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

struct addrinfo		*network_get_servinfo(char *i_ip_server, char *i_port)
{
	struct addrinfo	hints;
	struct addrinfo	*o_servinfo;
	char			*error_msg;
	int				ret;

	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if (!i_ip_server)
		hints.ai_flags = AI_PASSIVE;
	if ((ret = getaddrinfo(i_ip_server, i_port, &hints, &o_servinfo)) != 0)
	{
		error_msg = (char *)gai_strerror(ret);
		ft_dprintf(2, "Getaddrinfo: %s\n", error_msg);
		return (NULL);
	}
	return (o_servinfo);
}
