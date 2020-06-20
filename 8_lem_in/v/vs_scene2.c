/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_scene2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:25:48 by ediego            #+#    #+#             */
/*   Updated: 2020/03/08 17:39:04 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		vs_find_room(t_room *cur, char *name)
{
	int i;

	i = -1;
	while (cur[++i].name)
	{
		if (!(ft_strcmp(cur[i].name, name)))
			break ;
	}
	return (i);
}

void	vs_write_command(t_vs *vs, char *command, t_room *cur)
{
	char	**room_ant;
	int		index_room;

	if ((room_ant = ft_strsplit(command, '-')) == NULL)
		vs_exit(vs, NULL, 0);
	index_room = vs_find_room(cur, room_ant[1]);
	ft_strdel(&cur[index_room].name_ant);
	if ((cur[index_room].name_ant = ft_strsub(room_ant[0], 1,
		ft_strlen(room_ant[0]) - 1)) == NULL)
		vs_exit(vs, NULL, 0);
	if (ft_atoi(cur[index_room].name_ant) > vs->max_ant)
		vs->max_ant = ft_atoi(cur[index_room].name_ant);
	vs_free_split(room_ant);
}

int		vs_read_command(t_vs *vs, t_room *cur)
{
	int		num_ants;
	char	**command;
	char	*line;

	num_ants = -1;
	if (get_next_line(STDIN_FILENO, &line))
	{
		if ((command = ft_strsplit(line, ' ')) == NULL)
			vs_exit(vs, line, 0);
	}
	else
	{
		mlx_string_put(vs->ptr, vs->win, 600, 600, RD, "FINISH");
		return (0);
	}
	ft_strdel(&line);
	while (command[++num_ants])
		vs_write_command(vs, command[num_ants], cur);
	vs_free_split(command);
	return (num_ants);
}

void	vs_ant_out(t_vs *vs, int i)
{
	t_room	*cur;
	int		x;
	int		y;

	cur = vs->map->room;
	x = vs_x(vs, cur[i].x) - ((10 * vs->scale) + (1 / vs->scale));
	y = vs_y(vs, cur[i].y) - ((15 * vs->scale) + (1 / vs->scale));
	if (cur[i].name_ant)
	{
		mlx_string_put(vs->ptr, vs->win, x, y, FL, cur[i].name_ant);
		ft_strdel(&cur[i].name_ant);
	}
}

void	vs_ant_start(t_vs *vs, t_room *cur)
{
	if (vs->map->num_ants - vs->max_ant > 0)
	{
		ft_strdel(&cur[vs->map->start].name_ant);
		cur[vs->map->start].name_ant = ft_itoa(vs->map->num_ants - vs->max_ant);
		cur[vs->map->start].status = 1;
		vs_circle(vs, vs->map->start, vs->r);
		vs_ant_out(vs, vs->map->start);
	}
	else
	{
		vs->map->num_ants = 0;
		ft_strdel(&cur[vs->map->start].name_ant);
		cur[vs->map->start].status = 0;
		vs_circle(vs, vs->map->start, vs->r);
	}
}
