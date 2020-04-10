/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mamory_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:30:27 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/03 18:49:15 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline void	ft_memcpy_big_endian(void *dst, const void *src, int size)
{
	int		dst_byte;
	int		src_byte;

	dst_byte = 0;
	src_byte = size - 1;
	while (src_byte > -1)
	{
		((unsigned char*)dst)[dst_byte] = ((unsigned char*)src)[src_byte];
		++dst_byte;
		--src_byte;
	}
}

inline void	memory_rd_dir(t_memory i_m, int i_a, void *m_dst, int i_s)
{
	ft_memcpy_big_endian(m_dst, i_mem->mem + relevant_address, i_size);
}

inline int	memory_convert_address_to_relevant(t_memory *i_mem, int i_row_addr)
{
	if (i_addres >= MEM_SIZE)
		return (i_addres % MEM_SIZE);
	return (i_row_addr);
}

void		memory_read(t_memory *i_mem, int i_addres, void *m_dst, int	i_size)
{
	int		relevant_address;
	int		mem_to_end;

	if (i_size > -1 && i_size <= MEM_SIZE)
	{
		relevant_address = memory_convert_address_to_relevant(i_mem, i_addres);
		if ((mem_to_end = MEM_SIZE - relevant_address) < i_size)
		{
			memory_rd_dir(i_mem, relevant_address, m_dst, mem_to_end);
			memory_rd_dir(i_mem, 0, m_dst + mem_to_end, i_size - mem_to_end);
		}
		else
			ft_memcpy_big_endian(m_dst, i_mem->mem + relevant_address, i_size);
	}
	else
		save_error_to_log("Memory ", "Can't read invalid size ");
}
