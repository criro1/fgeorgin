/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_increase_cycle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:48:28 by astamm            #+#    #+#             */
/*   Updated: 2020/03/08 17:51:07 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_increase_cycle(long cycle, int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_CHANGE_CYCLES;
		size_package = 8;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &cycle, 8);
	}
}
