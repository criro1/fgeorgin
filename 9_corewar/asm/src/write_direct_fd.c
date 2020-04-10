/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_direct_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:55:01 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 03:12:40 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		case_1_local(int direct, int fd, int dir_size)
{
	unsigned	test;
	unsigned	res;

	test = (unsigned)direct;
	if (dir_size == 2)
	{
		test = test & 0xffff;
		res = ((test << 8) | (test >> 8)) & 0xffff;
	}
	else if (dir_size == 4)
		res = (((test << 24) & 0xff000000) | ((test << 8) & 0xff0000) |
								((test >> 8) & 0xff00) | ((test >> 24) & 0xff));
	write(fd, &res, dir_size);
}

static void		case_2_local(int direct, int fd, int dir_size)
{
	unsigned	test;
	unsigned	res;

	test = (unsigned)direct;
	if (dir_size == 2)
	{
		test = test & 0xffff;
		res = (((test >> 8) & 0xff) | ((test << 8) & 0xff00));
	}
	else if (dir_size == 4)
	{
		test = test & 0xffffffff;
		res = (((test << 24) & 0xff000000) | ((test << 8) & 0xff0000) |
								((test >> 8) & 0xff00) | ((test >> 24) & 0xff));
	}
	write(fd, &res, dir_size);
}

void			write_direct_fd(char *content, int fd, int dir_size)
{
	int			direct;

	if ((direct = ft_atoi(++content)) >= 0)
		case_1_local(direct, fd, dir_size);
	else
		case_2_local(direct, fd, dir_size);
}
