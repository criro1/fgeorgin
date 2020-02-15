/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:46:43 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/13 21:47:06 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_head(t_str *head)
{
	while (head)
	{
		if (head->line)
			free(head->line);
		free(head);
		head = head->next;
	}
}

void		ft_exit(t_map *map, char *line, int err)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (map->room[i].name)
	{
		while (map->room[i].links)
		{
			tmp = map->room[i].links->next;
			free(map->room[i].links);
			map->room[i].links = tmp;
		}
		free(map->room[i].name);
		i++;
	}
	if (line)
		free(line);
	ft_free_head(map->head);
	free(map);
	if (err == 0)
		write(2, "Error\n", 6);
	if (err == 0)
		exit(0);
}

void		ft_solution(t_map *map, t_room *room)
{
	int			*way;
	t_map		*sh_w;
	t_map		*tmp;
	t_w_and_d	*st;

	way = ft_bfs(map, room[map->start], room[map->start], 0);
	if (map->num_ants > way[0])
	{
		sh_w = ft_copy_map(map);
		tmp = ft_copy_map(map);
		ft_if_n_ways(map, sh_w, tmp);
		st = ft_do_ways_diff(map, sh_w);
		ft_ants_to_ways(map, st);
		ft_free_st(st);
		ft_exit(sh_w, NULL, 1);
		ft_exit(tmp, NULL, 1);
	}
	else
	{
		map->min = 1;
		ft_output_into_bfs(map, 1, way, 2);
		ft_putchar('\n');
	}
	free(way);
}

int			main(void)
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->out = (t_str*)ft_memalloc(sizeof(t_str));
	map->head = map->out;
	ft_valid(map, 0);
	ft_output_lines(map->head);
	ft_solution(map, map->room);
	ft_exit(map, NULL, 1);
	return (0);
}
