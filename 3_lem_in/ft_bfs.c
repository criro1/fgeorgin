/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:27:02 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/13 21:27:07 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*ft_ret_way(int **way, t_room curr_room, int min)
{
	free(*way);
	(*way) = (int*)ft_memalloc(sizeof(int) * (min + 2));
	(*way)[0] = min;
	(*way)[min + 1] = curr_room.num;
	return (*way);
}

void		ft_if_rs_w(int **room_struct, int **way, t_room curr_room, int min)
{
	if ((*room_struct)[0] < (*way)[0])
	{
		free(*way);
		(*way) = (*room_struct);
		(*way)[min + 1] = curr_room.num;
	}
	else
		free(*room_struct);
}

int			*ft_bfs(t_map *map, t_room curr_r, t_room prev_r, int min)
{
	int		*r_st;
	int		*way;
	t_link	*tmp;

	tmp = curr_r.links;
	way = (int*)ft_memalloc(sizeof(int));
	way[0] = 2147483647;
	while (tmp)
	{
		if ((map->room[tmp->link_num].x == prev_r.x && map->room[tmp->
			link_num].y == prev_r.y) || (map->room[tmp->link_num].level == 1))
		{
			if (curr_r.num == map->end)
				return (ft_ret_way(&way, curr_r, min));
			tmp = tmp->next;
			continue ;
		}
		if (curr_r.num == map->end)
			return (ft_ret_way(&way, curr_r, min));
		else
			r_st = ft_bfs(map, map->room[tmp->link_num], curr_r, min + 1);
		tmp = tmp->next;
		ft_if_rs_w(&r_st, &way, curr_r, min);
	}
	return (way);
}
