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

void 	ft_del_links(t_map *map, int from, int what)
{
	t_link *tmp;
	t_link *for_free;

	if (map->room[from].links->link_num != what)
	{
		tmp = map->room[from].links;
		while (tmp->next->link_num != what)
			tmp = tmp->next;
		for_free = tmp->next;
		tmp->next = tmp->next->next;
		free(for_free);
	}
	else
	{
		for_free = map->room[from].links;
		map->room[from].links = map->room[from].links->next;
		free(for_free);
	}
}

void 	ret_1_2(t_map *map, t_map *sh_w)
{
	int i;

	i = 0;
	while (sh_w->room[i].name)
	{
		if (sh_w->room[i].links)
		{
			sh_w->room[i].links->next = map->room[i].links;
			map->room[i].links = sh_w->room[i].links;
			sh_w->room[i].links = NULL;
		}
		i++;
	}
}

void	ft_del_1_2(t_map *map, int *way, int *wout)
{
	int 	i;
	int 	j;

	i = wout[0] + 1;
	while (i >= 2)
	{
		j = 1;
		while (j <= way[0])
		{
			if (wout[i] == way[j] && wout[i - 1] == way[j + 1])
			{
				ft_del_links(map, way[j], way[j + 1]);
				ft_del_links(map, way[j + 1], way[j]);
			}
			j++;
		}
		i--;
	}
}

int		ft_num_of_links(t_map *map, int num_of_room)
{
	t_link *tmp;
	int i;

	i = 0;
	tmp = map->room[num_of_room].links;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_output_into_bfs(t_map *map, int ants, int *way, int room)
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

int 	ft_output(t_map *map, int ants, int **ways, int room)
{
	
}

void	ft_solution(t_map *map, t_room *room)
{
	int *way;
	int *wout;
	t_map *sh_w;
	int **all = NULL;

	wout = NULL;
	sh_w = (t_map*)ft_memalloc(sizeof(t_map));
	int i;
	i = 0;
	while (room[i].name)
	{
		sh_w->room[i].name = ft_strdup(room[i].name);
		sh_w->room[i].num = room[i].num;
		i++;
	}
	way = ft_bfs(map, room[map->start], room[map->start], 0);
	if (map->num_ants > way[0])
	{
		ft_move_sh_w(map, sh_w, way);
		wout = ft_bfs(map, map->room[map->start], map->room[map->start], 0);
		ret_1_2(map, sh_w);
		ft_del_1_2(map, way, wout);
		free(wout);
		i = 0;
		all = (int**)ft_memalloc(sizeof(int*) * ft_num_of_links(map, map->start));
		while (map->room[map->start].links)
		{
			wout = ft_bfs(map, map->room[map->start], map->room[map->start], 0);
			all[i++] = wout;
			ft_move_sh_w(map, sh_w, wout);
		}
		map->data = i;
		ft_output(map, 1, all, 2);
		while (i--)
			free(all[i]);
		free(all);
	}
	else
	{
		map->min = 1;
		ft_output_into_bfs(map, 1, way, 2);
		ft_putchar('\n');
	}
	// i = 1;
	// printf("min steps to end = %d\n", all[0][0]);
	// while (i <= all[0][0] + 1)
	// {
	// 	printf("%s\n", map->room[all[0][i]].name);
	// 	i++;
	// }
	// i = 1;
	// printf("min steps to end = %d\n", all[1][0]);
	// while (i <= all[1][0] + 1)
	// {
	// 	printf("%s\n", map->room[all[1][i]].name);
	// 	i++;
	// }
	// t_link *tmp;
	// i = 0;
	// while (map->room[i].name)
	// {
	// 	printf("I'm in room %s\n", map->room[i].name);
	// 	tmp = map->room[i].links;
	// 	while (tmp)
	// 	{
	// 		printf("%s\n", map->room[tmp->link_num].name);
	// 		tmp = tmp->next;
	// 	}
	// 	i++;
	// }
	// if (wout)
	// 	free(wout);
	if (sh_w)
		ft_exit(sh_w, NULL, 1);
	free(way);
}

int		main(void)
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	ft_valid(map, 0);
	ft_solution(map, map->room);
	ft_exit(map, NULL, 1);
	return (0);
}
