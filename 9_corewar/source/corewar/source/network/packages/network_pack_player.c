/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_pack_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:32:30 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/13 21:54:50 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**								STRUCT PAKEGE
**	| sign begin | size content | code pakege | content | code pakege | sign end
**  +------------+--------------+-------------+---------+-------------+---------
**  |  4 byte    |    4 byte    |    4 byte   | unlim   |   4 byte    |  4 byte
**  ----------------------------------------------------------------------------
**
**							STRUCT CONTENT PLAYER
**  | size name | name  | size comment | comment | size mem champ | code champ |
**  +-----------+-------+--------------+---------+----------------+------------+
**  |  4 byte   | unlim |    4 byte    |  unlim  |    4 byte      |  unlim     |
**  ----------------------------------------------------------------------------
**
**	Array "size[4]" stored :
**		size[0] = size name player
**		size[1] = size comment player
**		size[2] = sise content in paket
**		size[3] = size pakege
*/

static inline void	init_size_pakege_player(unsigned *m_size,
															t_player *i_player)
{
	m_size[0] = ft_strlen(i_player->name);
	m_size[1] = ft_strlen(i_player->comment);
	m_size[2] = m_size[0] + m_size[1] + i_player->size_bytes + 4 + 4 + 4;
	m_size[3] = m_size[2] + PAKEGE_HEDER_SIZE + PAKEGE_END_SIZE;
}

static inline void	*put_content_pl(void *m_dst, unsigned *i_size,
																t_player *i_pl)
{
	unsigned char	*o_iterator;

	o_iterator = m_dst;
	o_iterator = ft_memcpy(o_iterator, &(i_size[0]), 4) + 4;
	o_iterator = ft_memcpy(o_iterator, i_pl->name, i_size[0]) + i_size[0];
	o_iterator = ft_memcpy(o_iterator, &(i_size[1]), 4) + 4;
	o_iterator = ft_memcpy(o_iterator, i_pl->comment, i_size[1]) + i_size[1];
	o_iterator = ft_memcpy(o_iterator, &i_pl->size_bytes, 4) + 4;
	o_iterator = ft_memcpy(o_iterator, i_pl->mem_champion, i_pl->size_bytes)
															+ i_pl->size_bytes;
	return ((void*)o_iterator);
}

int					network_pack_player(t_player *i_player, t_pack_net *m_pack)
{
	unsigned		size[4];
	unsigned char	*data_ptr;

	ft_bzero(m_pack, sizeof(t_pack_net));
	init_size_pakege_player(size, i_player);
	if ((m_pack->data = (unsigned char*)ft_memalloc(size[3])))
	{
		data_ptr = m_pack->data;
		data_ptr = net_package_put_header(data_ptr, size[2],
															PAKEGE_PLAYER_CODE);
		data_ptr = put_content_pl(data_ptr, size, i_player);
		net_package_put_end(data_ptr, PAKEGE_PLAYER_CODE);
		m_pack->size = size[3];
	}
	else
	{
		perror("Can't paking player");
		return (-1);
	}
	return (0);
}
