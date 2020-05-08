/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:30:27 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:44:32 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	revers_cpy_memory(void *m_dst, void *m_src, int m_size)
{
	unsigned char	*dst_byte;
	unsigned char	*src_byte;

	dst_byte = m_dst;
	src_byte = m_src;
	while (m_size--)
		*dst_byte-- = *src_byte++;
}

static inline int	memory_convert_address_to_relevant(int i_row_addr)
{
	if (i_row_addr < 0)
		return (MEM_SIZE + i_row_addr);
	else if (i_row_addr >= MEM_SIZE)
		return (i_row_addr % MEM_SIZE);
	return (i_row_addr);
}

void				memory_read(t_memory *i_mem, int i_addres, void *m_dst,
																	int i_size)
{
	int				relevant_address;
	int				mem_to_end;
	unsigned char	*dst;
	unsigned char	*src;

	if (i_size > -1 && i_size <= MEM_SIZE)
	{
		relevant_address = memory_convert_address_to_relevant(i_addres);
		dst = (unsigned char*)(((unsigned char*)m_dst) + (i_size - 1));
		src = i_mem->mem + relevant_address;
		if ((mem_to_end = MEM_SIZE - relevant_address) < i_size)
		{
			revers_cpy_memory(dst, src, mem_to_end);
			revers_cpy_memory(dst - mem_to_end, i_mem->mem,
														i_size - mem_to_end);
		}
		else
			revers_cpy_memory(dst, src, i_size);
	}
	else
		save_error_to_log("Memory ", "Can't read invalid size ");
}
