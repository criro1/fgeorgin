/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_memory_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 19:07:17 by artem             #+#    #+#             */
/*   Updated: 2020/04/22 19:13:00 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			print_memory_from_fd(struct pollfd *i_fds)
{
	unsigned char	buff[BUFF_SIZE];
	int				ret_poll;
	int				timeout;
	int				read_byte;

	timeout = 500;
	while (((ret_poll = poll(i_fds, 1, timeout)) > 0))
	{
		ft_bzero(buff, BUFF_SIZE);
		if ((read_byte = read(i_fds->fd, buff, BUFF_SIZE)) < 0)
			perror("Debug print memory fd");
		else
			print_memory(buff, read_byte);
	}
	if (ret_poll < 0)
		perror("Debug print memory fd");
}

void				debug_print_memory_fd(int i_fd)
{
	struct pollfd	fds;
	int				ret_poll;
	int				timeout;

	timeout = 50000;
	fds.fd = i_fd;
	fds.events = POLLIN;
	ret_poll = poll(&fds, 1, timeout);
	if (!ret_poll)
		ft_dprintf(2, "Timeout(%d msecs)\n", timeout);
	else if (ret_poll < 0)
		perror("Debug print memory fd");
	else
		print_memory_from_fd(&fds);
}
