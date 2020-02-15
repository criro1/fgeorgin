/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ways_diff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:50:13 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/13 21:50:15 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_num_of_links(t_map *map, int num_of_room)
{
	t_link	*tmp;
	int		i;

	i = 0;
	tmp = map->room[num_of_room].links;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			ft_output_into_bfs(t_map *map, int ants, int *way, int room)
{
	while (ants <= map->num_ants && room <= way[0] + 1)
	{
		ft_printf("L%d-%s ", ants, map->room[way[room]].name);
		if (room != 2)
			if (ft_output_into_bfs(map, ants + 1, way, room - 1) == 0
				&& ants != map->min)
				return (0);
		if ((ants == map->num_ants && ants != 1) || (room == 2 && ants != 1))
			return (0);
		if (room != way[0] + 1)
			ft_putchar('\n');
		room++;
	}
	if (ants + 1 <= map->num_ants)
	{
		ft_putchar('\n');
		map->min = ants + 1;
		ft_output_into_bfs(map, ants + 1, way, room - 1);
	}
	return (1);
}

t_w_and_d	*ft_do_ways_diff(t_map *map, t_map *sh_w)
{
	int			i;
	int			j;
	int			*wout;
	t_w_and_d	*st;

	st = (t_w_and_d*)ft_memalloc(sizeof(t_w_and_d));
	i = 0;
	st->ways = (int**)ft_memalloc(sizeof(int*) *
		ft_num_of_links(map, map->start) + 1);
	while (map->room[map->start].links)
	{
		wout = ft_bfs(map, map->room[map->start], map->room[map->start], 0);
		st->ways[i++] = wout;
		ft_move_sh_w(map, sh_w, wout);
	}
	st->ways[i] = NULL;
	st->diff = (int*)ft_memalloc(sizeof(int) * i);
	j = 1;
	while (j < i)
	{
		st->diff[j] = st->ways[j][0] - st->ways[j - 1][0] + st->diff[j - 1];
		j++;
	}
	st->diff_len = j;
	return (st);
}
