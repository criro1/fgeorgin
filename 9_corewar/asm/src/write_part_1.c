/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_part_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:55:57 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 02:02:11 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_indirect_fd(char *content, int fd)
{
	int			indirect;
	unsigned	test;
	unsigned	res;

	if ((indirect = ft_atoi(content)) >= 0)
	{
		test = (unsigned)indirect;
		test = test & 0xffff;
		res = ((test << 8) | (test >> 8)) & 0xffff;
		write(fd, &res, 2);
	}
	else
	{
		test = (unsigned)indirect;
		test = test & 0xffff;
		res = ((test << 8) & 0xffff) | ((test >> 8) & 0xffff);
		write(fd, &res, 2);
	}
}

void			write_indir_label_fd(int label_bc, int fd)
{
	unsigned	res;
	unsigned	test;

	if (label_bc >= 0)
		res = ((label_bc << 8) | (label_bc >> 8)) & 0xffff;
	else
	{
		test = (unsigned)label_bc;
		test = test & 0xffff;
		res = ((test << 8) & 0xffff) | ((test >> 8) & 0xffff);
	}
	write(fd, &res, 2);
}

void			write_register_fd(char *content, int fd)
{
	unsigned	reg;

	reg = ft_atoi(++content);
	write(fd, &reg, 1);
}
