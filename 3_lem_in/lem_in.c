/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:37:35 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/12/08 19:37:37 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// int		ft_bfs(t_map *map, t_room curr_room, t_room prev_room, int min)
// {
// 	printf("name = %s\n", curr_room.name);
// 	t_link *tmp;
// 	tmp = curr_room.links;
// 	int i = 9999999;
// 	int count = 0;
// 	while (tmp)
// 	{
// 		if ((map->room[tmp->link_num].x == prev_room.x
// 			&& map->room[tmp->link_num].y == prev_room.y)
// 			|| (map->room[tmp->link_num].level == 1))
// 			{
// 				tmp = tmp->next;
// 				continue ;
// 			}
// 		if (curr_room.num == map->end)
// 			return (min);
// 		else
// 			count = ft_bfs(map, map->room[tmp->link_num], curr_room, min + 1);
// 		tmp = tmp->next;
// 		if (count < i)
// 			i = count;
// 		printf("name = %s\n", curr_room.name);
// 	}
// 	return (i);
// }

// void	ft_solution(t_map *map, t_room *room)
// {
// 	int num = ft_bfs(map, room[map->start], room[map->start], 0);
//     printf("res = %d\n", num);
// }

int		*ft_ret_way(int **way, t_room curr_room, int min)
{
	free(*way);
	(*way) = (int*)ft_memalloc(sizeof(int) * (min + 2));
	(*way)[0] = min;
	(*way)[min + 1] = curr_room.num;
	return (*way);
}

void	ft_if_rs_w(int **room_struct, int **way, t_room curr_room, int min)
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

int		*ft_bfs(t_map *map, t_room curr_room, t_room prev_room, int min)
{
	int *room_struct;
	int *way;
	t_link *tmp;
	
	tmp = curr_room.links;
	way = (int*)ft_memalloc(sizeof(int));
	way[0] = 2147483647;
	while (tmp)
	{
		if ((map->room[tmp->link_num].x == prev_room.x && map->room[tmp->
			link_num].y == prev_room.y) || (map->room[tmp->link_num].level == 1))
			{
				if (curr_room.num == map->end)
					return (ft_ret_way(&way, curr_room, min));
				tmp = tmp->next;
				continue ;
			}
		if (curr_room.num == map->end)
			return (ft_ret_way(&way, curr_room, min));
		else
			room_struct = ft_bfs(map, map->room[tmp->link_num], curr_room, min + 1);
		tmp = tmp->next;
		ft_if_rs_w(&room_struct, &way, curr_room, min);
	}
	return (way);
}

void	ft_move_sh_w(t_map *map, t_map *sh_w, int *way)
{
	int 	i;
	t_link	*tmp;

	i = 1;
	while (i <= way[0])
	{
		if (map->room[way[i]].links->link_num != way[i + 1])
		{
			tmp = map->room[way[i]].links;
			while (tmp->next->link_num != way[i + 1])
				tmp = tmp->next;
			sh_w->room[way[i]].links = tmp->next;
			tmp->next = tmp->next->next;
			sh_w->room[way[i]].links->next = NULL;
		}
		else
		{
			sh_w->room[way[i]].links = map->room[way[i]].links;
			map->room[way[i]].links = map->room[way[i]].links->next;
			sh_w->room[way[i]].links->next = NULL;	
		}
		i++;
	}
}

void	ft_del_1_2(t_map *map, t_map *sh_w, int *way, int *wout)
{
	int 	i;
	int 	j;
	t_link	*tmp;

	i = wout[0] + 2;
	while (--i >= 2)
	{
		j = 0;
		while (++j <= way[0])
			if (wout[i] == way[j] && wout[i - 1] == way[j + 1])
			{
				if (map->room[way[j + 1]].links->link_num != way[j])
				{
					tmp = map->room[way[j + 1]].links;
					while (tmp->next->link_num != way[j])
						tmp = tmp->next;
					sh_w->room[way[j + 1]].links = tmp->next;
					tmp->next = tmp->next->next;
					sh_w->room[way[j + 1]].links->next = NULL;
				}
				else
				{
					sh_w->room[way[j + 1]].links = map->room[way[j + 1]].links;
					map->room[way[j + 1]].links = map->room[way[j + 1]].links->next;
					sh_w->room[way[j + 1]].links->next = NULL;	
				}
			}
	}
}
void	ft_solution(t_map *map, t_room *room)
{
	int *way;
	int i;
	t_map *sh_w;

	sh_w = (t_map*)ft_memalloc(sizeof(t_map));
	i = 0;
	while (room[i].name)
	{
		sh_w->room[i].name = ft_strdup(room[i].name);
		sh_w->room[i].num = room[i].num;
		i++;
	}
	way = ft_bfs(map, room[map->start], room[map->start], 0);
	// i = 1;
	// printf("min steps to end = %d\n", way[0]);
	// while (i <= way[0] + 1)
	// {
	// 	printf("%s\n", map->room[way[i]].name);
	// 	i++;
	// }

	
	

	ft_move_sh_w(map, sh_w, way);

	int *wout;
	wout = ft_bfs(map, map->room[map->start], map->room[map->start], 0);
	ft_del_1_2(map, sh_w, way, wout);

	i = 0;
	while (map->room[i].name)
	{
		printf("I'm in room %s\n", map->room[i].name);
		while (map->room[i].links)
		{
			printf("%s\n", map->room[map->room[i].links->link_num].name);
			map->room[i].links = map->room[i].links->next;
		}
		i++;
	}

	free(wout);
	ft_exit(sh_w, NULL, 1);
	free(way);
}

int		main()
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	ft_valid(map, 0);
	ft_solution(map, map->room);
	ft_exit(map, NULL, 1);
	return (0);
}
