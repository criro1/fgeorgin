/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_write_in_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:18:59 by astamm            #+#    #+#             */
/*   Updated: 2020/03/16 18:25:17 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	y_no_last_string(int *y, int *x, int sqrt_arena)
{
	if (*x > (sqrt_arena * 3))
	{
		*y += 1;
		if (*y > sqrt_arena)
			*y = 1;
		*x = 2;
	}
}

static inline void	y_last_string(int *y, int *x, t_visu *visu)
{
	if (*x > (visu->bytes_in_last_str * 3))
	{
		*y += 1;
		if (*y > visu->amount_string)
			*y = 1;
		*x = 2;
	}
}

static void			print_modified_mem(t_visu *visu, unsigned char *mem,
																int y, int x)
{
	int counter;

	counter = 0;
	while (counter != 4)
	{
		mvwprintw(visu->w_arena, y, x, "%02x", mem[counter]);
		x += 3;
		if (y != visu->amount_string)
			y_no_last_string(&y, &x, visu->sqrt_arena);
		else
			y_last_string(&y, &x, visu);
		counter++;
	}
}

void				visu_write_in_mem(t_visu *visu, t_package *package)
{
	int				id;
	int				byte_number;
	int				mem;
	int				y_x[2];
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&id, content, 4);
	content += 4;
	ft_memcpy(&byte_number, content, 4);
	content += 4;
	ft_memcpy(&mem, content, 4);
	mem = (unsigned int)number_reverse_mem((unsigned int)mem);
	y_x[0] = 0;
	set_y_x(&y_x[0], &y_x[1], byte_number, visu);
	wattrset(visu->w_arena,
		COLOR_PAIR(visu->struct_carriages.carriages[id]->color_pair_player));
	print_modified_mem(visu, (unsigned char*)&mem, y_x[0], y_x[1]);
	wrefresh(visu->w_arena);
}
