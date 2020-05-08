/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_end_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:07:46 by astamm            #+#    #+#             */
/*   Updated: 2020/03/08 17:50:53 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_end_game(int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		size_package = 0;
		code_package = CODE_PACKAGE_END_GAME;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
	}
}
