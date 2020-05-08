/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_player_say_live.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 09:33:24 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 09:35:31 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_player_say_live(int player, long cycle, int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_PLAYER_SAY_LIVE;
		size_package = 4 + 8;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &player, 4);
		write(fd, &cycle, 8);
	}
}
