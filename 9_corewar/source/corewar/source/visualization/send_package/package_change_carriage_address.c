/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_change_carriage_address.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:59:16 by astamm            #+#    #+#             */
/*   Updated: 2020/03/10 19:34:35 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_change_carriage_address(int id, int address, int fd)
{
	int	code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		size_package = 4 + 4;
		code_package = CODE_PACKAGE_CHANGE_CARRIAGE_ADDRESS;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &id, 4);
		write(fd, &address, 4);
	}
}
