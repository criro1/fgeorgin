/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_pakage_get_header.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:16:33 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 13:49:03 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	network_pakage_get_header(t_net_buff *m_buff, t_pak_header *m_head)
{
	int			end_find_header;
	unsigned	sign_begin;
	t_boolean	o_find_header;

	o_find_header = False;
	sign_begin = PAKEGE_SIGN_BEGIN;
	ft_bzero(m_head, sizeof(t_pak_header));
	end_find_header = m_buff->index_uploaded_to -
						(PAKEGE_HEDER_SIZE + PAKEGE_END_SIZE);
	--(m_buff->index_stop);
	while (!o_find_header && ++(m_buff->index_stop) <= end_find_header)
		if (!(ft_memcmp(&(m_buff->entry[m_buff->index_stop]), &sign_begin, 4)))
			o_find_header = True;
	if (o_find_header)
	{
		ft_memmove(&(m_head->pakage_size),
				&(m_buff->entry[m_buff->index_stop + 4]), 4);
		ft_memmove(&(m_head->pakage_code),
				&(m_buff->entry[m_buff->index_stop + 8]), 4);
	}
	return (o_find_header);
}
