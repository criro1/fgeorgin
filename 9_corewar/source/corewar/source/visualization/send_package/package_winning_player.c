/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_winning_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:11:11 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 17:17:21 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_winning_player(int number_player, int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_WINNING_PLAYER;
		size_package = 4;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &number_player, 4);
	}
}
