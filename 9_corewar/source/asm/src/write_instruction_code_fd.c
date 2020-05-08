/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction_code_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:02:27 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 02:24:28 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		part_1_local(int fd, char *content)
{
	if (!ft_strcmp(content, "live"))
		write(fd, "\x01", 1);
	else if (!ft_strcmp(content, "ld"))
		write(fd, "\x02", 1);
	else if (!ft_strcmp(content, "st"))
		write(fd, "\x03", 1);
	else if (!ft_strcmp(content, "add"))
		write(fd, "\x04", 1);
	else if (!ft_strcmp(content, "sub"))
		write(fd, "\x05", 1);
	else if (!ft_strcmp(content, "and"))
		write(fd, "\x06", 1);
	else if (!ft_strcmp(content, "or"))
		write(fd, "\x07", 1);
	else if (!ft_strcmp(content, "xor"))
		write(fd, "\x08", 1);
}

static void		part_2_local(int fd, char *content)
{
	if (!ft_strcmp(content, "zjmp"))
		write(fd, "\x09", 1);
	else if (!ft_strcmp(content, "ldi"))
		write(fd, "\x0a", 1);
	else if (!ft_strcmp(content, "sti"))
		write(fd, "\x0b", 1);
	else if (!ft_strcmp(content, "fork"))
		write(fd, "\x0c", 1);
	else if (!ft_strcmp(content, "lld"))
		write(fd, "\x0d", 1);
	else if (!ft_strcmp(content, "lldi"))
		write(fd, "\x0e", 1);
	else if (!ft_strcmp(content, "lfork"))
		write(fd, "\x0f", 1);
	else if (!ft_strcmp(content, "aff"))
		write(fd, "\x10", 1);
}

/*
**	always returns 0 to reset	curr_bc_tmp
*/

int				write_instruction_code_fd(char *content, int fd)
{
	part_1_local(fd, content);
	part_2_local(fd, content);
	return (0);
}
