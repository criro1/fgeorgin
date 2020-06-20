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

void		ft_duplicate_room(t_map *map, int cur_ind, t_room *cur)
{
	int duplicate;

	duplicate = map->sum_r + map->sum_d;
	cur[duplicate].num = cur[cur_ind].num;
	cur[cur_ind].ind_out_room = duplicate;
	cur[duplicate].ind_out_room = cur_ind;
	cur[duplicate].name = ft_strjoin(cur[cur_ind].name, " Out");
	cur[cur_ind].ind_out_room = duplicate;
	cur[duplicate].links = cur[cur_ind].links;
	cur[cur_ind].links = NULL;
}

int			*ft_make_dup_room_1(int *arr)
{
	int *res;
	int i;

	res = (int*)ft_memalloc(sizeof(int) * arr[0] + 1);
	i = 0;
	while (i < arr[0] + 1)
	{
		res[i] = arr[i];
		i++;
	}
	return (res);
}

int			*ft_make_dup_room(t_map *map, int *way)
{
	int		room;
	t_room	*cur;
	int		arr[1000];

	room = 2;
	cur = map->room;
	arr[0] = 0;
	while (room <= way[0])
	{
		if (map->room[way[room]].ind_out_room == -1)
		{
			ft_duplicate_room(map, way[room], cur);
			map->sum_d++;
		}
		else
		{
			arr[arr[0] + 1] = way[room];
			arr[0]++;
		}
		room++;
	}
	return (ft_make_dup_room_1(arr));
}

void		ft_suurballe(t_map *map, int *way)
{
	int *res;

	res = ft_make_dup_room(map, way);
	map->tmp = map->sum_d - 1;
	ft_make_dup_link(map, way, res);
	free(res);
}
