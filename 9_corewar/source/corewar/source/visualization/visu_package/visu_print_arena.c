/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:24:49 by astamm            #+#    #+#             */
/*   Updated: 2020/03/13 16:34:45 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_color_for_current_byte(t_visu_gamers *gamers,
													WINDOW **w_arena, int byte)
{
	int			index;
	t_boolean	color_set;

	color_set = False;
	index = 0;
	while (index < gamers->amount && color_set == False)
	{
		if (byte >= gamers->player[index].byte_start_code &&
								byte <= gamers->player[index].byte_end_code)
		{
			wattrset(*w_arena, COLOR_PAIR(gamers->player[index].color_pair));
			color_set = True;
		}
		index++;
	}
	if (color_set == False)
		wattrset(*w_arena, COLOR_PAIR(COLOR_PAIR_GRAY_VISU));
}

void		print_one_str_in_arena(t_visu *visu, unsigned char *mem,
													int y, int *current_byte)
{
	int i;
	int x;
	int	bytes_in_str;

	x = 2;
	i = 0;
	if (y != visu->amount_string)
		bytes_in_str = 64;
	else
		bytes_in_str = visu->bytes_in_last_str;
	while (i < bytes_in_str)
	{
		set_color_for_current_byte(&visu->gamers, &visu->w_arena,
																*current_byte);
		mvwprintw(visu->w_arena, y, x, "%02x", mem[i]);
		*current_byte += 1;
		x += 3;
		i++;
	}
}

void		print_arena(t_visu *visu)
{
	unsigned char	*mem;
	int				byte_in_str;
	int				y;
	int				current_byte;

	curs_set(0);
	noecho();
	mem = visu->arena;
	byte_in_str = visu->sqrt_arena;
	current_byte = 0;
	y = 1;
	while (y <= visu->amount_string)
	{
		print_one_str_in_arena(visu, mem, y, &current_byte);
		wrefresh(visu->w_arena);
		delay_output(15);
		mem += byte_in_str;
		y++;
	}
}
