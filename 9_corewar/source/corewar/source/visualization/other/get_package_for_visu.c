/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_package_for_visu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:41:28 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 16:05:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_package	get_package(int fd)
{
	t_package	new;

	ft_bzero(&new, sizeof(t_package));
	read(fd, &new.code_package, SIZE_CODE_PACKAGE);
	read(fd, &new.size_package, 4);
	if (new.size_package > 0)
	{
		new.content = ft_memalloc(new.size_package);
		read(fd, new.content, new.size_package);
	}
	else
		new.content = NULL;
	return (new);
}
