/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dir_label_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 03:06:21 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 03:14:19 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		case_1_local(int label_bc, int fd, int dir_size)
{
	unsigned	test;
	unsigned	res;

	test = (unsigned)label_bc;
	if (dir_size == 2)
	{
		test = test & 0xffff;
		res = ((test << 8) | (test >> 8)) & 0xffff;
	}
	else if (dir_size == 4)
		res = ((test << 24) | (test >> 24)) & 0xffffffff;
	write(fd, &res, dir_size);
}

static void		case_2_local(int label_bc, int fd, int dir_size)
{
	unsigned	test;
	unsigned	res;

	test = (unsigned)label_bc;
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

void			write_dir_label_fd(int label_bc, int fd, int dir_size)
{
	if (label_bc >= 0)
		case_1_local(label_bc, fd, dir_size);
	else
		case_2_local(label_bc, fd, dir_size);
}
