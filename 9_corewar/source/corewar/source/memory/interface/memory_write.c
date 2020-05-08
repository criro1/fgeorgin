/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:37:36 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:45:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	read_get_relevant_address(int i_row_address)
{
	if (i_row_address < 0)
		return (MEM_SIZE + i_row_address);
	else if (i_row_address < MEM_SIZE)
		return (i_row_address);
	return (i_row_address % MEM_SIZE);
}

static inline void	revers_cpy_memory(void *m_dst, void *m_src, int m_size)
{
	unsigned char	*dst_byte;
	unsigned char	*src_byte;

	dst_byte = m_dst;
	src_byte = m_src;
	while (m_size--)
		*dst_byte++ = *src_byte--;
}

void				memory_write(t_memory *i_mem, int i_addr, void *m_src,
																	int i_size)
{
	unsigned char	*src_byte;
	unsigned char	*dst_byte;
	int				byte_to_end;
	int				relevant_address;

	src_byte = ((unsigned char*)((unsigned char*)m_src) + (i_size - 1));
	relevant_address = read_get_relevant_address(i_addr);
	byte_to_end = MEM_SIZE - relevant_address;
	dst_byte = i_mem->mem + relevant_address;
	if (i_size > byte_to_end)
	{
		revers_cpy_memory(dst_byte, src_byte, byte_to_end);
		revers_cpy_memory(i_mem->mem, src_byte - byte_to_end,
													i_size - byte_to_end);
	}
	else
		revers_cpy_memory(dst_byte, src_byte, i_size);
}
