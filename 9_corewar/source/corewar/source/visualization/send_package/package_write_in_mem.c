/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_write_in_mem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:44:19 by astamm            #+#    #+#             */
/*   Updated: 2020/03/14 21:47:38 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_write_in_mem(int mem, int byte_number, int id, int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		size_package = 4 + 4 + 4;
		code_package = CODE_PACKAGE_WRITE_IN_MEM;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &id, 4);
		write(fd, &byte_number, 4);
		write(fd, &mem, 4);
	}
}
