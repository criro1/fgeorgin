/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_death_carriage.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:43:35 by astamm            #+#    #+#             */
/*   Updated: 2020/03/15 15:47:10 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_death_carriage(int id_carriage, int amount_carriages, int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_DEATH_CARRIAGE;
		size_package = 4 + 4;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &id_carriage, 4);
		write(fd, &amount_carriages, 4);
	}
}
