/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_end_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:18:06 by astamm            #+#    #+#             */
/*   Updated: 2020/03/07 21:06:40 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_end_init(int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		size_package = 0;
		code_package = CODE_PACKAGE_END_INIT;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
	}
}
