/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:20:12 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/13 19:55:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	connect_destroy(t_connect **m_connect)
{
	t_connect	*connect;
	int			index_fd;

	connect = *m_connect;
	if (g_options & O_SERVER)
	{
		pthread_join(connect->thread[3], NULL);
	}
	index_fd = 0;
	while (index_fd < connect->connect_players)
	{
		if (connect->connectfd[index_fd] > 0)
			close(connect->connectfd[index_fd]);
		++index_fd;
	}
	if (connect->sockfd > 0)
		close(connect->sockfd);
	ft_memdel((void**)m_connect);
}
