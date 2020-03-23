/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suurballe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:17:45 by ediego            #+#    #+#             */
/*   Updated: 2020/02/25 19:44:01 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"





void	ft_duplicate_room(t_map *map, int cur_ind, t_room *cur)
{
	int duplicate;

	duplicate = map->sum_r + map->sum_d;
	cur[duplicate].num = cur[cur_ind].num;
	// cur[duplicate].dup = 1;
	cur[duplicate].name = ft_strjoin(cur[cur_ind].name, " Out");
	cur[cur_ind].ind_out_room = duplicate;
	cur[duplicate].links = cur[cur_ind].links;
	cur[cur_ind].links = NULL;
	// printf("\nname: %s, num: %d = %d\n", cur[duplicate].name, cur[duplicate].num, duplicate);
}

void	 	ft_make_dup_room(t_map *map, int *way)
{
	int room_in_way;
	int room;
	t_room *cur;

	room = 2;
	// map->sum_d = map->sum_r; //sum_d - sum_r = count duplicates rooms
	room_in_way = way[0];
	cur = map->room;
	while (room <= room_in_way)
	{
		ft_duplicate_room(map, way[room], cur);
		map->sum_d++; // after (sum_r - 1) counts rooms duplicates, before - originals
		room++;
	}
}

void	ft_dup_link(t_map *map, int end, int start, t_room *cur)
{
	t_link *iter;

	iter = cur[end].links;
	while (iter && iter->link_num != cur[start].num)
		iter = iter->next;
	if (iter && cur[start].ind_out_room != -1)
	{
		iter->link_num = cur[start].ind_out_room;
		iter->weight = -1;
	}
	else if (!iter && cur[start].ind_out_room != -1)
	{
		make_link(map, cur[end].num, cur[start].ind_out_room);
		cur[end].links->weight = -1;
	}
	else
	{
		make_link(map, cur[end].num, cur[start].num);
		cur[end].links->weight = -1;
	}
	//======================================================================
	// This create link for OUR room
	// two part 
	if (cur[end].ind_out_room != -1)
	{
		iter = cur[cur[end].ind_out_room].links;
		// while (iter && iter->link_num != start) // it's bad
		while (iter && iter->link_num != start) // it's bad =====fgeorgin добавил iter &&
			iter = iter->next;
		if (iter)
		{
			iter->link_num = end;
			iter->weight = 0;
		}
	}
}

void	ft_make_dup_link(t_map *map, int *way)
{
	int count;
	// int i;
	t_room *cur;

	cur = map->room;
	// i = way[0];
	count = way[0] + 1;
	while (count >= 2)
	{
		ft_dup_link(map, way[count], way[count - 1], cur);
		count--;
	}
}

void		ft_suurballe(t_map *map, int *way)
{
	// ft_print_map(map);
	// printf("\nSUURBALE\n");
	
	ft_make_dup_room(map, way);
	map->tmp = 	map->sum_d - 1;
	ft_make_dup_link(map, way);

	// ft_print_map(map);
	// exit (1);
	// printf("\nSUURBALE\n"); 
}





void		ft_print_way(t_map *map, int *way)
{
	int i;
	t_room *cur;

	cur = map->room;
	if (way[0] == 2147483647)
		return ;
	i = 0;
	printf("\nWay\n");
	while (++i <= (way[0] + 1))
		printf("\nRoom in way: %s\n", cur[way[i]].name);
}








