/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_init_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:06:13 by astamm            #+#    #+#             */
/*   Updated: 2020/03/07 21:06:56 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_init_memory(unsigned char *mem, size_t mem_size, int fd)
{
	int code_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_MEMORY;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &mem_size, 4);
		write(fd, mem, mem_size);
	}
}
