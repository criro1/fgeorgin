/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:30:27 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/06 13:09:08 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	ft_memcpy_big_endian(void *dst, const void *src, int size)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	src_cpy = (unsigned char*)src;
	dst_cpy = (unsigned char*)dst;
	while (size-- > 0)
		*dst_cpy-- = *src_cpy++;
}

static inline void	memory_rd_dir(t_memory *i_m, int i_a, void *m_dst, int i_s)
{
	ft_memcpy_big_endian(m_dst, i_m->mem + i_a, i_s);
}

static inline int	memory_convert_address_to_relevant(int i_row_addr)
{
	if (i_row_addr >= MEM_SIZE)
		return (i_row_addr % MEM_SIZE);
	return (i_row_addr);
}

void		memory_read(t_memory *i_mem, int i_addres, void *m_dst, int	i_size)
{
	int		relevant_address;
	int		mem_to_end;
	char	*dst;

	if (i_size > -1 && i_size <= MEM_SIZE)
	{
		relevant_address = memory_convert_address_to_relevant(i_addres);
		dst = m_dst + (i_size - 1);
		if ((mem_to_end = MEM_SIZE - relevant_address) < i_size)
		{
			memory_rd_dir(i_mem, relevant_address, dst, mem_to_end);
			relevant_address = 0;
			memory_rd_dir(i_mem, relevant_address, dst, i_size - mem_to_end);
		}
		else
			ft_memcpy_big_endian(m_dst, i_mem->mem + relevant_address, i_size);
	}
	else
		save_error_to_log("Memory ", "Can't read invalid size ");
}
