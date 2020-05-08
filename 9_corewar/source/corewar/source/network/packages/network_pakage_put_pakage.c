/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_pakage_put_pakage.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:58:37 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:02:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	valid_pakage(t_net_buff *m_buff, t_pack_net *m_pakage,
														t_pak_header *i_header)
{
	unsigned	code_in_end;
	unsigned	sign_end;

	code_in_end = 0;
	sign_end = 0;
	ft_memmove(&code_in_end, &(m_buff->entry[m_buff->index_stop +
				PAKEGE_HEDER_SIZE + i_header->pakage_size]), 4);
	ft_memmove(&sign_end, &(m_buff->entry[m_buff->index_stop +
				PAKEGE_HEDER_SIZE + i_header->pakage_size + 4]), 4);
	if (sign_end != PAKEGE_SIGN_END)
	{
		m_buff->index_stop += PAKEGE_HEDER_SIZE + PAKEGE_END_SIZE +
													i_header->pakage_size;
		return (0);
	}
	if (code_in_end != i_header->pakage_code)
		m_pakage->error_f |= PAKEGE_ERROR_DIFCOD_F;
	return (1);
}

int					network_pakage_put_pack_net(t_net_buff *m_buff,
								t_pack_net *m_pakage, t_pak_header *i_header)
{
	unsigned		size_loaded;
	int				ret_load;
	unsigned char	*new_mem;

	size_loaded = m_buff->index_uploaded_to - m_buff->index_stop;
	if (i_header->pakage_size > size_loaded)
		if ((ret_load = network_pakage_load_from_net(m_buff)) < 0)
			return (-1);
	size_loaded = m_buff->index_uploaded_to - m_buff->index_stop;
	if (i_header->pakage_size > size_loaded ||
			!valid_pakage(m_buff, m_pakage, i_header))
		return (0);
	if (!(new_mem = ft_memalloc(i_header->pakage_size)))
		return (-1);
	ft_memmove(new_mem, &(m_buff->entry[m_buff->index_stop +
				PAKEGE_HEDER_SIZE]), i_header->pakage_size);
	m_pakage->data = new_mem;
	m_pakage->size = i_header->pakage_size;
	m_pakage->code = i_header->pakage_code;
	m_buff->index_stop += i_header->pakage_size + PAKEGE_HEDER_SIZE +
															PAKEGE_END_SIZE;
	return (1);
}
