/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:00:14 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:42:24 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_byte_mem(unsigned char *mem, long term)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < term)
			ft_printf("%02x", mem[i]);
		else
			ft_printf("  ");
		if (i == 7)
			ft_printf("  ");
		else if (i < 15)
			ft_printf(" ");
		++i;
	}
}

static void	print_char_mem(unsigned char *mem, long term)
{
	int	i;

	i = 0;
	while (i < term && i < 16)
	{
		if (mem[i] > 31 && mem[i] < 127)
			ft_printf("%c", mem[i]);
		else
			ft_printf(".");
		++i;
	}
}

void		print_memory(void *i_mem, size_t i_size)
{
	unsigned char	*mem;
	size_t			shift;
	long			term;

	if (i_size)
	{
		shift = 0;
		mem = i_mem;
		term = i_size;
		while (term > 0)
		{
			ft_printf("%08x", shift);
			ft_printf("  ");
			print_byte_mem(mem, term);
			ft_printf("  |");
			print_char_mem(mem, term);
			ft_printf("|\n");
			shift += 16;
			mem += 16;
			term -= 16;
		}
		ft_printf("%08x\n", i_size);
	}
}
