/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_fetch_data_to_buff.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 19:19:19 by artem             #+#    #+#             */
/*   Updated: 2020/04/22 19:53:26 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		recive_full_data(t_buff *m_buff, struct pollfd *i_fds)
{
	unsigned char	*place_stop_recv;
	int				recv_bytes;

	recv_bytes = 0;
	place_stop_recv = m_buff->data;
	while (!errno && m_buff->size_data != m_buff->size_memory)
	{
		if ((recv_bytes = recv(i_fds->fd, place_stop_recv,
							m_buff->size_memory - m_buff->size_data, 0)) < 0)
			perror("Received data");
		place_stop_recv += recv_bytes;
		m_buff->size_data += recv_bytes;
	}
}

static void		poll_and_recv_data(t_buff *m_buff, struct pollfd *i_fds, int tm)
{
	int		ret_poll;

	if ((ret_poll = poll(i_fds, 1, tm)) < 0)
		perror("Fetch data from server");
	else if (!ret_poll)
		ft_dprintf(2, "Timeout fetch data(%d msec)\n", timeout);
	else
	{
		if (!(m_buff->data = ft_memalloc(m_buff->size_memory)))
			perror("Fetch data from server");
		recive_full_data(m_buff, i_fds);
	}
}

void			network_fetch_data_to_buff(t_buff *m_buff, struct pollfd *i_fds)
{
	int		ret_poll;
	int		timeout;

	ret_poll = 0;
	timeout = 100000;
	ret_poll = poll(i_fds, 1, timeout);
	if (ret_poll < 0)
		perror("Fetch size data from server");
	else if (!ret_poll)
		ft_dprintf(2, "Timeout fetch size data from serv(%d msec)\n", timeout);
	else
	{
		if ((recv(i_fds->fd, &m_buff->size_memory, 8, 0)) != 8)
			perror("Received size data");
		else
			poll_and_recv_data(m_buff, i_fds, timeout);
	}
}
