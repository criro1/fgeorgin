/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_decrease_ctd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:02:11 by astamm            #+#    #+#             */
/*   Updated: 2020/03/09 22:07:23 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	package_decrease_ctd(int cycle_to_die, int fd)
{
	int code_package;
	int	size_package;

	if (g_options & O_VISU)
	{
		code_package = CODE_PACKAGE_CHANGE_CTD;
		size_package = 4;
		write(fd, &code_package, SIZE_CODE_PACKAGE);
		write(fd, &size_package, 4);
		write(fd, &cycle_to_die, 4);
	}
}
