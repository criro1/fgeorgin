/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suurballe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:17:45 by ediego            #+#    #+#             */
/*   Updated: 2020/02/24 20:07:59 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_duplicate_room(t_map *map, int cur_ind, t_room *cur)
{
	int duplicate;
	t_link *iter_link;

	 
	duplicate = map->sum_d;
	cur[duplicate].num = cur[cur_ind].num;
	cur[duplicate].name = cur[cur_ind].name;//ft_strjoin("Out ", cur[cur_ind].name);
	iter_link = cur[cur_ind].links;
	map->room[cur_ind].ind_out_room = duplicate;
	while (iter_link)
	{
		if(iter_link->weight == -1)
			make_link(map, duplicate, cur_ind);
		else
		{
			make_link(map, duplicate, iter_link->link_num);
			cur[duplicate].dup = 1;
			iter_link->link_num = cur_ind;
		}
		iter_link = iter_link->next;
	}
	// printf("\nname: %s, num: %d = %d\n", cur[duplicate].name, cur[duplicate].num, duplicate);
}

void	 	ft_make_dup_room(t_map *map, int *way)
{
	int count;
	int i;
	t_room *cur;

	i = 2;
	map->sum_d = map->sum_r; //sum_d - sum_r = count duplicates rooms
	count = way[0];
	cur = map->room;
	while (i <= count)
	{
		ft_duplicate_room(map, way[i], cur);
		map->sum_d++; // after (sum_r - 1) counts rooms duplicates, before - originals
		i++;
	}
}

void	ft_dup_link(t_map *map, int i, t_room *cur)
{
	t_link *iter_link;

	iter_link = cur[i].links;
	// i--;
	while (iter_link)
	{
		if (iter_link->weight == -1 && map->tmp >= map->sum_r)
			iter_link->link_num = map->tmp--;
		iter_link = iter_link->next;
	}
}

void	ft_make_dup_link(t_map *map, int *way)
{
	int count;
	int i;
	t_room *cur;

	cur = map->room;
	i = way[0];
	count = way[0] + 1;
	while (count > 1)
	{
		ft_dup_link(map, way[count], cur);
		count--;
	}
	
}

void		ft_suurballe(t_map *map, int *way)
{
	ft_make_dup_room(map, way);
	map->tmp = 	map->sum_d - 1;
	ft_make_dup_link(map, way);
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