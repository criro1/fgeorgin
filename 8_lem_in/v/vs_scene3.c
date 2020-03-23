/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_scene3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:34:08 by ediego            #+#    #+#             */
/*   Updated: 2020/02/24 19:47:51 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		vs_x(t_vs *vs, int x)
{
	return ((vs->scale * (((x - vs->minx) * vs->dx) + 100)) + vs->xx);
}

int		vs_y(t_vs *vs, int y)
{
	return ((vs->scale * ((y - vs->miny) * vs->dy) + 100) + vs->yy);
}

void	vs_output(t_vs *vs, float x, float y, int status)
{
	float x0;
	float y0;

	x *= vs->scale;
	y *= vs->scale;
	x0 = vs->x;
	y0 = vs->y;
	mlx_pixel_put(vs->ptr, vs->win, x0 + x, y0 + y, status ? YE : GR);
	mlx_pixel_put(vs->ptr, vs->win, x0 + x, y0 - y, status ? YE : GR);
	mlx_pixel_put(vs->ptr, vs->win, x0 - x, y0 + y, status ? YE : GR);
	mlx_pixel_put(vs->ptr, vs->win, x0 - x, y0 - y, status ? YE : GR);
}

void	vs_out(t_vs *vs, int status, float r)
{
	float x;
	float y;
	float delta;
	float error;

	x = 0;
	y = r;
	delta = (1 - 2 * y) * vs->scale;
	while (y >= 0)
	{
		vs_output(vs, x, y, status);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
		{
			delta += 2 * ++x + 1;
			continue ;
		}
		if ((delta > 0) && (error > 0))
		{
			delta -= 2 * --y + 1;
			continue ;
		}
		delta += 2 * (++x - y--);
	}
}

void	vs_circle(t_vs *vs, int i, int r)
{
	t_room *cur;

	cur = vs->map->room;
	vs->x = vs_x(vs, cur[i].x);
	vs->y = vs_y(vs, cur[i].y);
	if (cur[i].name_ant)
		cur[i].status = 1;
	while (r--)
		vs_out(vs, cur[i].status, r);
}
