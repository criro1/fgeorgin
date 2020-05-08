/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_get_next_pakage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:54:03 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/11 10:10:40 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_net_buff	*new_net_buff(int i_fd)
{
	t_net_buff	*o_new;

	if (!(o_new = ft_memalloc(sizeof(t_net_buff))))
		return (NULL);
	o_new->fds.fd = i_fd;
	o_new->fds.events = POLLIN;
	if (!(o_new->entry = ft_memalloc(NET_BUFF_SIZE)))
	{
		ft_memdel((void**)&o_new);
		return (NULL);
	}
	o_new->mem_size = NET_BUFF_SIZE;
	return (o_new);
}

static int			get_pakege(t_net_buff *m_buff, t_pack_net *m_pakage)
{
	int				ret_load;
	t_boolean		have_header;
	t_pak_header	header;

	have_header = False;
	while (!have_header)
	{
		have_header = network_pakage_get_header(m_buff, &header);
		if (have_header)
		{
			if (network_pakages_realloc_mem(m_buff,
					(header.pakage_size + PAKEGE_END_SIZE + PAKEGE_HEDER_SIZE)
						- (m_buff->index_uploaded_to - m_buff->index_stop)) < 0)
				return (-1);
			if (network_pakage_put_pack_net(m_buff, m_pakage, &header) < 0)
				return (-1);
		}
		else if (network_pakages_realloc_mem(m_buff, NET_BUFF_SIZE) < 0 ||
				(ret_load = network_pakage_load_from_net(m_buff)) < 0)
			return (-1);
		else if (ret_load == 0)
			return (0);
	}
	return (1);
}

int					net_get_next_pakage(int fd_from, t_pack_net *m_pakage)
{
	static t_net_buff	*buff[10240];

	if (!m_pakage || fd_from < 0)
		return (-1);
	ft_bzero(m_pakage, sizeof(t_pack_net));
	if (!buff[fd_from])
		if (!(buff[fd_from] = new_net_buff(fd_from)))
			return (-1);
	if (get_pakege(buff[fd_from], m_pakage) < 0)
		return (-1);
	return (m_pakage->size);
}
