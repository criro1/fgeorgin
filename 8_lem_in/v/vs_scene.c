/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:00:17 by ediego            #+#    #+#             */
/*   Updated: 2020/02/24 19:48:02 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

float	vs_module(float x)
{
	return (x < 0) ? -x : x;
}

float	vs_max(float x, float y)
{
	x = vs_module(x);
	y = vs_module(y);
	if (x > y)
		return (x);
	return (y);
}

void	vs_bras(t_vs *vs, float x2, float y2)
{
	float	xstep;
	float	ystep;
	int		max_step;
	int		count;

	count = 0;
	xstep = x2 - vs->x;
	ystep = y2 - vs->y;
	max_step = vs_max(xstep, ystep);
	xstep /= max_step;
	ystep /= max_step;
	while ((int)(x2 - vs->x) || (int)(y2 - vs->y))
	{
		if (count++ > (vs->r * vs->scale)
		&& (vs->x + (vs->r * vs->scale) < x2 ||
		vs->y + (vs->r * vs->scale) < y2))
			mlx_pixel_put(vs->ptr, vs->win, vs->x, vs->y, BK);
		vs->x += xstep;
		vs->y += ystep;
	}
}

void	vs_line(t_vs *vs)
{
	t_room	*cur;
	t_link	*iter;
	int		i;
	float	x2;
	float	y2;

	cur = vs->map->room;
	i = -1;
	while (cur[++i].name)
	{
		iter = cur[i].links;
		while (iter)
		{
			x2 = vs_x(vs, cur[iter->link_num].x);
			y2 = vs_y(vs, cur[iter->link_num].y);
			vs->x = vs_x(vs, cur[i].x);
			vs->y = vs_y(vs, cur[i].y);
			vs_bras(vs, x2, y2);
			iter = iter->next;
		}
	}
}

void	vs_scene(t_vs *vs)
{
	t_room	*cur;
	int		i;
	int		x;
	int		y;

	i = -1;
	cur = vs->map->room;
	vs->r = 30;
	vs_background(vs);
	vs_line(vs);
	while (cur[++i].name)
	{
		x = vs_x(vs, cur[i].x) - ((vs->r / 2) * vs->scale);
		y = vs_y(vs, cur[i].y) + (vs->r * vs->scale);
		vs_circle(vs, i, vs->r);
		mlx_string_put(vs->ptr, vs->win, x, y, WH, cur[i].name);
		vs_ant_out(vs, i);
		vs_ant_start(vs, cur);
	}
}
