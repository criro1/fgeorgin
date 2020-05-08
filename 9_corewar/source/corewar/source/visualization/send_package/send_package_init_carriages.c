/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_package_init_carriages.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:07:22 by astamm            #+#    #+#             */
/*   Updated: 2020/03/14 19:58:23 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	send_package_init_carriages(t_carriages *carriages, int fd)
{
	t_itercarr	carriter;
	int			code_package;
	int			size_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_NEW_CARRIAGE;
		size_package = 4 + 4;
		carriages_init_iterator(carriages, &carriter);
		while (carriter.have_carriage)
		{
			write(fd, &code_package, SIZE_CODE_PACKAGE);
			write(fd, &size_package, 4);
			write(fd, &carriter.carriage->id, 4);
			write(fd, &carriter.carriage->address, 4);
			carriages_iterator_set_next(&carriter);
		}
	}
}
