/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_broadcast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:39:17 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 20:02:49 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "sys/wait.h"

static void		network_send_all(t_connect *i_connect, t_buff *buff)
{
	int			index;
	int			pid;
	int			debug;

	index = 0;
	debug = 0;
	while (index < i_connect->connect_players)
	{
		if (!(pid = fork()))
		{
			if (send(i_connect->connectfd[index],
					&buff->size_data, 8, 0) < 0 ||
						((debug = send(i_connect->connectfd[index],
										buff->data, buff->size_data, 0)) < 0))
				perror("Broadcast can't send pakage");
		}
		++index;
	}
	if (pid)
	{
		write(i_connect->out_fd, buff->data, buff->size_data);
		wait(NULL);
	}
}

static void		init_buff(t_buff *buff)
{
	ft_bzero(buff, sizeof(t_buff));
	buff->data = ft_memalloc(BUFF_SIZE);
	if (!errno)
		buff->size_memory = BUFF_SIZE;
}

static void		memory_control(t_buff *buff, int add_size)
{
	if (buff->size_data + add_size > buff->size_memory)
		if ((buff->data = realloc(buff->data, buff->size_memory + BUFF_SIZE)))
			buff->size_memory += BUFF_SIZE;
}

static t_buff	fetch_data(struct pollfd *fds)
{
	unsigned char	buff_read[BUFF_SIZE];
	t_buff			buff;
	int				ret_poll;
	int				ret_read;

	init_buff(&buff);
	ret_poll = poll(fds, 1, 50000);
	while (!errno && ret_poll)
	{
		ft_bzero(buff_read, BUFF_SIZE);
		if (!errno && (ret_poll = poll(fds, 1, 500)) > 0)
		{
			if ((ret_read = read(fds->fd, buff_read, BUFF_SIZE)) > 0)
			{
				memory_control(&buff, ret_read);
				if (!errno)
				{
					ft_memcpy(buff.data + buff.size_data, buff_read, ret_read);
					buff.size_data += ret_read;
				}
			}
		}
	}
	return (buff);
}

void			*network_broadcast(void *m_connect)
{
	t_buff		buff;
	t_connect	*connect;

	connect = m_connect;
	if (m_connect)
	{
		buff = fetch_data(&(connect->in_fds));
		network_send_all(connect, &buff);
	}
	pthread_exit(0);
}
