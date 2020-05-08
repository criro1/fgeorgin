/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_recv_players.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:40:00 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 14:40:15 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_player	*network_load_player(int fd_player)
{
	t_player	*rec_player;
	t_pack_net	pakage;

	net_get_next_pakage(fd_player, &pakage);
	rec_player = network_unpack_player(&pakage);
	network_package_free(&pakage);
	return (rec_player);
}

void			*network_recv_players(void *m_connect)
{
	int			current_player;
	t_connect	*connect;
	t_player	*new_player;
	t_boolean	all_load;

	connect = m_connect;
	current_player = 0;
	all_load = False;
	while (!all_load)
	{
		if (current_player < connect->connect_players)
		{
			new_player =
				network_load_player(connect->connectfd[current_player++]);
			add_to_players(connect->players, new_player);
		}
		else
			usleep(100000);
		if (!connect->connect && current_player >= connect->connect_players)
			all_load = True;
	}
	pthread_exit(0);
}
