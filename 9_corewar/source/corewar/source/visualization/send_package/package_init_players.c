/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_init_players.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:54:57 by astamm            #+#    #+#             */
/*   Updated: 2020/03/11 19:18:56 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_player(t_player *player, int fd)
{
	int		code_package;
	int		size_package;
	size_t	size_name;

	code_package = CODE_PACKAGE_PLAYER;
	size_name = ft_strlen(player->name);
	size_package = 4 + 4 + 4 + size_name;
	write(fd, &code_package, SIZE_CODE_PACKAGE);
	write(fd, &size_package, 4);
	write(fd, &player->order, 4);
	write(fd, &player->size_bytes, 4);
	write(fd, &size_name, 4);
	write(fd, player->name, size_name);
}

void	package_init_players(t_players *players, int fd)
{
	int counter;

	if (g_options & O_VISU)
	{
		counter = 0;
		while (counter != players->amount)
		{
			package_player(players->player[counter], fd);
			counter++;
		}
	}
}
