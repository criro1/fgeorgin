/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_pakage_load_from_net.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:44:59 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 13:46:41 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	network_pakage_load_from_net(t_net_buff *m_buff)
{
	int		byte_to_load;
	int		ret_poll;
	int		ret_rec;

	ret_poll = 0;
	ret_rec = 0;
	byte_to_load = m_buff->mem_size - m_buff->index_uploaded_to;
	ret_poll = poll((&(m_buff->fds)), 1, 10000);
	if (ret_poll == -1)
	{
		perror("Can't get next pakage poll");
		return (-1);
	}
	else if (ret_poll)
	{
		ret_rec = recv(m_buff->fds.fd,
				&(m_buff->entry[m_buff->index_uploaded_to]), byte_to_load, 0);
		if (ret_rec < 0)
			perror("Received next pakege");
		else
			m_buff->index_uploaded_to = m_buff->index_uploaded_to + ret_rec;
	}
	return (ret_rec);
}
