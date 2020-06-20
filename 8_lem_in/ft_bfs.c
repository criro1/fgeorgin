/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:27:02 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/08 13:56:33 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*ft_zero_way(t_map *map)
{
	int *way;

	way = (int*)ft_memalloc(sizeof(int) * 1);
	way[0] = 2147483647;
	ft_clear_map(map);
	return (way);
}

int			*ft_find_way_1(t_map *map, int count)
{
	int		*way;
	int		i;

	i = map->end;
	way = (int*)ft_memalloc(sizeof(int) * (count + 1));
	way[0] = count - 1;
	while (count > 0)
	{
		way[count] = i;
		i = map->parent[i];
		count--;
	}
	ft_clear_map(map);
	return (way);
}

int			*ft_find_way(t_map *map)
{
	int		l;
	t_room	*cur;
	int		count;
	char	*name;

	count = 0;
	cur = map->room;
	l = map->end;
	while (cur[l].name)
	{
		name = cur[l].name;
		if (cur[l].num == map->start)
		{
			count++;
			break ;
		}
		count++;
		l = map->parent[l];
	}
	return (ft_find_way_1(map, count));
}

void		ft_search_parent(t_map *map, int next_ind, int i, int i_q)
{
	t_room *iter;

	iter = map->room;
	iter[next_ind].visited = 1;
	if (iter[next_ind].ind_out_room != -1)
		iter[iter[next_ind].ind_out_room].visited = 1;
	if (iter[map->queue[i]].num != iter[next_ind].num)
		map->parent[iter[next_ind].num] = iter[map->queue[i]].num;
	map->queue[i_q] = next_ind;
}

int			*ft_bfs(t_map *map, t_room *iter, int next_ind)
{
	int		i;
	int		i_q;
	t_link	*iter_link;

	i = -1;
	map->parent = (int *)ft_memalloc(sizeof(int) * (map->sum_r + map->sum_d));
	map->queue = (int *)ft_memalloc(sizeof(int) * (map->sum_r + map->sum_d));
	map->queue[0] = iter[map->start].num;
	iter[map->start].visited = 1;
	i_q = 1;
	while (++i <= i_q)
	{
		if (iter[next_ind].num == map->end)
			return (ft_find_way(map));
		iter_link = iter[map->queue[i]].links;
		while (iter_link && iter[next_ind].num != map->end)
		{
			next_ind = iter_link->link_num;
			if (!iter[next_ind].visited)
				ft_search_parent(map, next_ind, i, i_q++);
			iter_link = iter_link->next;
		}
	}
	return (ft_zero_way(map));
}
