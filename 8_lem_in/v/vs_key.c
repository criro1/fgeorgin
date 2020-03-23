/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:27:27 by ediego            #+#    #+#             */
/*   Updated: 2020/02/24 19:48:13 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	vs_key_space(t_vs *vs)
{
	t_room	*cur;
	int		i;

	i = -1;
	cur = vs->map->room;
	vs_read_command(vs, cur);
	while (cur[++i].name)
	{
		if (cur[i].name_ant)
		{
			cur[i].status = 1;
			vs_circle(vs, i, vs->r);
			vs_ant_out(vs, i);
		}
		else
		{
			cur[i].status = 0;
			vs_circle(vs, i, vs->r);
		}
	}
	vs_ant_start(vs, cur);
}

void	vs_key_scale(t_vs *vs, int key)
{
	if (key == 27)
		vs->scale /= 1.1;
	if (key == 24)
		vs->scale *= 1.1;
	ft_strdel(&vs->map->room[vs->map->start].name_ant);
	vs_scene(vs);
}

void	vs_key_move(t_vs *vs, int key)
{
	if (key == 124)
		vs->xx += 30;
	if (key == 123)
		vs->xx -= 30;
	if (key == 125)
		vs->yy += 30;
	if (key == 126)
		vs->yy -= 30;
	vs_scene(vs);
}

int		key_press(int key, t_vs *vs)
{
	if (key == 49)
		vs_key_space(vs);
	if (key == 27 || key == 24)
		vs_key_scale(vs, key);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		vs_key_move(vs, key);
	if (key == 53)
		close1(vs);
	return (0);
}
