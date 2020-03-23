/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_scene4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:35:30 by ediego            #+#    #+#             */
/*   Updated: 2020/02/24 19:47:47 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	vs_calc_scale_scene(t_vs *vs, int *ddx, int *ddy)
{
	vs->dx = 1000 / (ddx[1] - ddx[0]);
	vs->dy = 1000 / (ddy[1] - ddy[0]);
	if (ddx[0] < 0)
		vs->minx = ddx[0] * -1;
	else
		vs->minx = ddx[0];
	if (ddy[0] < 0)
		vs->miny = ddy[0] * -1;
	else
		vs->miny = ddy[0];
}

void	vs_scale_scene(t_vs *vs)
{
	t_room	*cur;
	int		i;
	int		dx[2];
	int		dy[2];

	cur = vs->map->room;
	i = -1;
	dx[0] = cur[0].x;
	dy[0] = cur[0].y;
	dx[1] = cur[0].x;
	dy[1] = cur[0].y;
	while (cur[++i].name)
	{
		if (cur[i].x < dx[0])
			dx[0] = cur[i].x;
		if (cur[i].y < dy[0])
			dy[0] = cur[i].y;
		if (cur[i].x > dx[1])
			dx[1] = cur[i].x;
		if (cur[i].y > dy[1])
			dy[1] = cur[i].y;
	}
	vs_calc_scale_scene(vs, dx, dy);
}

void	vs_background(t_vs *vs)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x <= 1200)
	{
		while (++y <= 1200)
			mlx_pixel_put(vs->ptr, vs->win, x, y, 0x696969);
		y = -1;
	}
}
