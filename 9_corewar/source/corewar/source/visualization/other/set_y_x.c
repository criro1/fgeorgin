/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_y_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 14:19:31 by astamm            #+#    #+#             */
/*   Updated: 2020/03/14 14:20:22 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	y_last_line(int *y, int *x, int byte_number,
														int bytes_in_last_str)
{
	int div_y;
	int mod_x;

	div_y = byte_number / bytes_in_last_str;
	if (div_y == 0)
		*y = 1;
	else
		*y = div_y + 1;
	mod_x = byte_number % bytes_in_last_str;
	*x = mod_x;
	*x = *x * 3 + 2;
}

static inline void	y_no_last_line(int *y, int *x, int byte_number)
{
	int div_y;
	int mod_x;

	div_y = byte_number / BYTES_IN_STR;
	if (div_y == 0)
		*y = 1;
	else
		*y = div_y + 1;
	mod_x = byte_number % BYTES_IN_STR;
	*x = mod_x;
	*x = *x * 3 + 2;
}

void				set_y_x(int *y, int *x, int byte_number, t_visu *visu)
{
	if (byte_number == 0)
	{
		*y = 1;
		*x = 2;
	}
	else if (*y == visu->amount_string)
		y_last_line(y, x, byte_number, visu->bytes_in_last_str);
	else
		y_no_last_line(y, x, byte_number);
}
