/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_package_new_carriage.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:55:20 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 10:19:06 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	send_package_new_carriage(t_carriage *carriage, int id_parent,
												int amount_carriages, int fd)
{
	int			code_package;
	int			size_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_NEW_CARRIAGE;
		size_package = 4 + 4 + 4 + 4;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &carriage->id, 4);
		write(fd, &carriage->address, 4);
		write(fd, &id_parent, 4);
		write(fd, &amount_carriages, 4);
	}
}
