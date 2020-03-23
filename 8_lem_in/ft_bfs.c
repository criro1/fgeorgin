/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:27:02 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/25 18:46:41 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 	ft_clear_map(t_map *map, int *queue, int *parent)
{
	t_room *cur;
	int i;

	i = 0;
	cur = map->room;
	while (cur[i].name)
		cur[i++].visited = 0;
	if (queue)
		free(queue);
	if (parent)
		free(parent);
}

int		 *ft_zero_way(t_map *map, int *queue, int *parent)
{
	int *way;

	way = (int*)ft_memalloc(sizeof(int) * 1);
	way[0] = 2147483647;
	ft_clear_map(map, queue, parent);
	return (way);
}

int 	*ft_find_way(t_map *map, int *parent, int *queue)
{
	int i;
	int l;
	t_room *cur;
	int count;
	int *way;
	char *name;

	count = 0;
	i = map->end;
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
		l = parent[l];
	}
	way = (int*)ft_memalloc(sizeof(int) * (count + 1));
	way[0] = count - 1;
	while (count > 0)
	{
		way[count] = i;
		i = parent[i];
		count--;
	}
	ft_clear_map(map, parent, queue);
	return (way);
}

int			*ft_bfs(t_map *map, t_room *iter, int next_ind)
{
	int *queue;
	int *parent;
	int i;   
	int i_q;
	t_link *iter_link;

	i = -1;
	parent = (int *)ft_memalloc(sizeof(int) * map->sum_r);
	queue = (int *)ft_memalloc(sizeof(int) * map->sum_r);
	queue[0] = iter[map->start].num;
	iter[map->start].visited = 1;
	i_q = 1;
	while (++i <= i_q)
	{
		if (iter[next_ind].num == map->end)
			return (ft_find_way(map, parent, queue));
		iter_link = iter[queue[i]].links;
		while(iter_link && iter[next_ind].num != map->end)
		{
			next_ind = iter_link->link_num;
			if (!iter[iter_link->link_num].visited)
			{
				iter[iter_link->link_num].visited = 1;
				if (iter[queue[i]].num != iter[next_ind].num)
					parent[iter[iter_link->link_num].num] = iter[queue[i]].num;
				queue[i_q++] = iter_link->link_num;
			}
			iter_link = iter_link->next;
		}
	}
	return (ft_zero_way(map, parent, queue));
}
