/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_export_dump.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:16:57 by wmaykit           #+#    #+#             */
/*   Updated: 2020/05/01 10:42:10 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	memory_put_row(
		unsigned char *i_mem,
		int i_fd,
		int i_octets,
		int i_size)
{
	int	current_octet;

	current_octet = 0;
	while (current_octet < i_octets && current_octet < i_size)
	{
		ft_dprintf(i_fd, "%02x", i_mem[current_octet]);
		++current_octet;
		if (current_octet < i_octets)
			ft_dprintf(i_fd, " ");
	}
	ft_dprintf(i_fd, "\n");
}

void		memory_export_dump(t_memory *i_mem, int i_fd, int i_num_octets)
{
	int	size_mem;
	int	current_octet;

	size_mem = memory_get_size(i_mem);
	current_octet = 0;
	while (current_octet < size_mem)
	{
		ft_dprintf(i_fd, "%s%0.4x : ", "0x", current_octet);
		memory_put_row(i_mem->mem + current_octet, i_fd, i_num_octets,
													size_mem - current_octet);
		current_octet += i_num_octets;
	}
}
