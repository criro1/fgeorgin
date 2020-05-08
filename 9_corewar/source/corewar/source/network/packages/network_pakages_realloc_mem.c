/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_pakages_realloc_mem.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:55:29 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/05 18:42:01 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Function returned : 1 - added memory, 0 - do'n need exrta memory, -1 - error
*/

int	network_pakages_realloc_mem(t_net_buff *m_buff, int i_size_extra)
{
	unsigned char	*new_mem;
	int				size_free_mem;
	int				size_realloc;

	size_free_mem = m_buff->mem_size - m_buff->index_uploaded_to;
	if (size_free_mem > i_size_extra)
	{
		size_realloc = m_buff->index_uploaded_to - m_buff->index_stop;
		if (!(new_mem = ft_memalloc(i_size_extra + size_realloc)))
		{
			perror("Can't realloc net buff");
			return (-1);
		}
		ft_memmove(new_mem, &(m_buff->entry[m_buff->index_stop]), size_realloc);
		m_buff->index_stop = 0;
		m_buff->index_uploaded_to = size_realloc;
		ft_memdel((void**)&m_buff->entry);
		m_buff->entry = new_mem;
		new_mem = NULL;
		m_buff->mem_size = i_size_extra + size_realloc;
		return (1);
	}
	return (0);
}
