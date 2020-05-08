/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_send_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:25:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 15:00:30 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	network_send_player(t_connect *i_connect, t_player *i_player)
{
	t_pack_net	pakege;

	network_pack_player(i_player, &pakege);
	if (!errno && send(i_connect->sockfd, pakege.data, pakege.size, 0) < 0)
		perror("send player pakege");
	network_package_free(&pakege);
	print_memory(pakege.data, pakege.size);
}
