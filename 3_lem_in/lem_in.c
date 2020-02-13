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

/*
int		ft_bfs(t_map *map, t_room curr_room, t_room prev_room, int min)
{
	printf("name = %s\n", curr_room.name);
	t_link *tmp;
	tmp = curr_room.links;
	int i = 9999999;
	int count = 0;
	while (tmp)
	{
		if ((map->room[tmp->link_num].x == prev_room.x
			&& map->room[tmp->link_num].y == prev_room.y)
			|| (map->room[tmp->link_num].level == 1))
			{
				tmp = tmp->next;
				continue ;
			}
		if (curr_room.num == map->end)
			return (min);
		else
			count = ft_bfs(map, map->room[tmp->link_num], curr_room, min + 1);
		tmp = tmp->next;
		if (count < i)
			i = count;
		printf("name = %s\n", curr_room.name);
	}
	return (i);
}

void	ft_solution(t_map *map, t_room *room)
{
	int num = ft_bfs(map, room[map->start], room[map->start], 0);
    printf("res = %d\n", num);
}
*/

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

int		*ft_bfs(t_map *map, t_room curr_r, t_room prev_r, int min)
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

void	ft_move_sh_w_1(t_map *map, t_map *sh_w, int *way, int i)
{
	t_link	*tmp;
	t_link	*tmp_sh;

	tmp = map->room[way[i]].links;
	while (tmp->next->link_num != way[i + 1])
		tmp = tmp->next;
	tmp_sh = sh_w->room[way[i]].links;
	if (tmp_sh && tmp_sh->next)
	{
		while (tmp_sh->next != NULL)
			tmp_sh = tmp_sh->next;
		tmp_sh->next = tmp->next;
		tmp_sh->next->next = NULL;
	}
	else if (tmp_sh && !tmp_sh->next)
	{
		sh_w->room[way[i]].links->next = tmp->next;
		sh_w->room[way[i]].links->next->next = NULL;
	}
	else
	{
		sh_w->room[way[i]].links = tmp->next;
		sh_w->room[way[i]].links->next = NULL;
	}
	tmp->next = tmp->next->next;
}

void	ft_move_sh_w_2(t_map *map, t_map *sh_w, int *way, int i)
{
	t_link	*tmp_sh;

	tmp_sh = sh_w->room[way[i]].links;
	if (tmp_sh && tmp_sh->next)
	{
		while (tmp_sh->next != NULL)
			tmp_sh = tmp_sh->next;
		tmp_sh->next = map->room[way[i]].links->next;
		map->room[way[i]].links->next = map->room[way[i]].links->next->next;
		tmp_sh->next->next = NULL;
	}
	else if (tmp_sh && !tmp_sh->next)
	{
		sh_w->room[way[i]].links->next = map->room[way[i]].links->next;
		map->room[way[i]].links->next = map->room[way[i]].links->next->next;
		sh_w->room[way[i]].links->next->next = NULL;
	}
	else
	{
		sh_w->room[way[i]].links = map->room[way[i]].links->next;
		map->room[way[i]].links->next = map->room[way[i]].links->next->next;
		sh_w->room[way[i]].links->next = NULL;
	}
}

void	ft_move_sh_w_3(t_map *map, t_map *sh_w, int *way, int i)
{
	t_link	*tmp_sh;

	tmp_sh = sh_w->room[way[i]].links;
	if (tmp_sh && tmp_sh->next)
	{
		while (tmp_sh->next != NULL)
			tmp_sh = tmp_sh->next;
		tmp_sh->next = map->room[way[i]].links;
		map->room[way[i]].links = map->room[way[i]].links->next;
		tmp_sh->next->next = NULL;
	}
	else if (tmp_sh && !tmp_sh->next)
	{
		sh_w->room[way[i]].links->next = map->room[way[i]].links;
		map->room[way[i]].links = map->room[way[i]].links->next;
		sh_w->room[way[i]].links->next->next = NULL;
	}
	else
	{
		sh_w->room[way[i]].links = map->room[way[i]].links;
		map->room[way[i]].links = map->room[way[i]].links->next;
		sh_w->room[way[i]].links->next = NULL;
	}
}

void	ft_move_sh_w(t_map *map, t_map *sh_w, int *way)
{
	int i;

	i = 1;
	while (i <= way[0])
	{
		if (map->room[way[i]].links->link_num != way[i + 1] &&
			map->room[way[i]].links->next->link_num != way[i + 1])
		{
			ft_move_sh_w_1(map, sh_w, way, i);
		}
		else if (map->room[way[i]].links->link_num != way[i + 1] &&
			map->room[way[i]].links->next->link_num == way[i + 1])
		{
			ft_move_sh_w_2(map, sh_w, way, i);
		}
		else if (map->room[way[i]].links->link_num == way[i + 1])
			ft_move_sh_w_3(map, sh_w, way, i);
		i++;
	}
}

void	ft_del_links(t_map *map, int from, int what)
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

void	ret_1_2(t_map *map, t_map *sh_w)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (sh_w->room[i].name)
	{
		if (sh_w->room[i].links && !(sh_w->room[i].links->next))
		{
			sh_w->room[i].links->next = map->room[i].links;
			map->room[i].links = sh_w->room[i].links;
			sh_w->room[i].links = NULL;
		}
		else if (sh_w->room[i].links && sh_w->room[i].links->next)
		{
			tmp = sh_w->room[i].links;
			while (sh_w->room[i].links->next)
				sh_w->room[i].links = sh_w->room[i].links->next;
			sh_w->room[i].links->next = map->room[i].links;
			map->room[i].links = tmp;
			sh_w->room[i].links = NULL;
		}
		i++;
	}
}

void	ft_del_1_2(t_map *map, int *way, int *wout)
{
	int	i;
	int	j;

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

int		ft_way_n_wout(int *way, int *wout)
{
	int i;
	int j;

	i = wout[0] + 1;
	while (i >= 2)
	{
		j = 1;
		while (j <= way[0])
		{
			if (wout[i] == way[j] && wout[i - 1] == way[j + 1])
				return (1);
			j++;
		}
		i--;
	}
	return (0);
}

t_map	*ft_copy_map(t_map *map)
{
	int		i;
	t_map	*sh_w;

	sh_w = (t_map*)ft_memalloc(sizeof(t_map));
	i = 0;
	while (map->room[i].name)
	{
		sh_w->room[i].name = ft_strdup(map->room[i].name);
		sh_w->room[i].num = map->room[i].num;
		i++;
	}
	return (sh_w);
}

void	ft_if_n_ways(t_map *map, t_map *sh_w, t_map *tmp)
{
	int *way;
	int *wout;

	while (map->room[map->start].links)
	{
		way = ft_bfs(map, map->room[map->start], map->room[map->start], 0);
		ft_move_sh_w(map, sh_w, way);
		while (map->room[map->start].links)
		{
			wout = ft_bfs(map, map->room[map->start], map->room[map->start], 0);
			if (ft_way_n_wout(way, wout))
			{
				ret_1_2(map, sh_w);
				ft_del_1_2(map, way, wout);
				ret_1_2(map, tmp);
				free(wout);
				continue ;
			}
			ft_move_sh_w(map, tmp, wout);
			free(wout);
		}
		free(way);
		ret_1_2(map, tmp);
	}
	ret_1_2(map, sh_w);
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

void	ft_add_ant(t_link **fin_j, int ant)
{
	t_link *tmp;

	if (!(*fin_j))
	{
		(*fin_j) = (t_link*)ft_memalloc(sizeof(t_link));
		(*fin_j)->link_num = ant;
		(*fin_j)->next = NULL;
	}
	else if ((*fin_j) && !((*fin_j)->next))
	{
		tmp = (t_link*)ft_memalloc(sizeof(t_link));
		tmp->link_num = ant;
		tmp->next = NULL;
		(*fin_j)->next = tmp;
	}
	else if ((*fin_j) && (*fin_j)->next)
	{
		tmp = (*fin_j);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_link*)ft_memalloc(sizeof(t_link));
		tmp->next->link_num = ant;
		tmp->next->next = NULL;
	}
}

void	ft_output(t_map *map, t_link *fin_j, int room, int *way)
{
	while (fin_j && fin_j->link_num <= map->num_ants
		&& (room <= way[0] + 1 && room >= 2))
	{
		ft_printf("L%d-%s ", fin_j->link_num, map->room[way[room]].name);
		fin_j = fin_j->next;
		room--;
	}
}

void	ft_do_tmp(t_link **fin, t_link **tmp, t_w_and_d *st, int stat)
{
	int i;

	i = 0;
	if (stat == 0)
	{
		while (i < st->diff_len)
		{
			tmp[i] = fin[i];
			i++;
		}
	}
	else if (stat == 1)
	{
		while (i < st->diff_len)
		{
			fin[i] = tmp[i];
			i++;
		}
	}
}

void	ft_print_ants(t_map *map, t_link **fin, t_w_and_d *st, int *room)
{
	int j;
	int res;
	t_link *tmp[st->diff_len];

	ft_do_tmp(fin, tmp, st, 0);
	res = 0;
	while (res < st->diff_len)
	{
		j = 0;
		res = 0;
		while (j < st->diff_len)
		{
			if (fin[j])
				ft_output(map, fin[j], room[j], st->ways[j]);
			if (fin[j] && room[j] == st->ways[j][0] + 1)
				fin[j] = fin[j]->next;
			else
				room[j]++;
			if (!fin[j])
				res++;
			j++;
		}
		ft_printf("\n");
	}
	ft_do_tmp(fin, tmp, st, 1);
}

void	ft_free_fin(t_link **fin, int diff_len, int *room)
{
	int i;

	i = 0;
	while (i < diff_len)
	{
		while (fin[i])
		{
			free(fin[i]);
			fin[i] = fin[i]->next;
		}
		i++;
	}
	free(fin);
	free(room);
}

int		*ft_malloc_roooms(int j)
{
	int *room;

	room = (int*)ft_memalloc(sizeof(int) * j);
	while (j--)
		room[j] = 2;
	return (room);
}

void	ft_ants_to_ways(t_map *map, t_w_and_d *st)
{
	t_link	**fin;
	int		ant;
	int		j;
	int		*room;

	fin = (t_link**)ft_memalloc(sizeof(t_link*) * st->diff_len);
	ant = 1;
	while (ant <= map->num_ants)
	{
		j = 0;
		while (j < st->diff_len)
		{
			if (map->num_ants + 1 - ant > st->diff[j])
			{
				ft_add_ant(&(fin[j]), ant);
				ant++;
			}
			j++;
		}
	}
	j = st->diff_len;
	room = ft_malloc_roooms(j);
	ft_print_ants(map, fin, st, room);
	ft_free_fin(fin, st->diff_len, room);
}

void	ft_free_st(t_w_and_d *st)
{
	int i;

	i = 0;
	while (i < st->diff_len)
	{
		free(st->ways[i]);
		i++;
	}
	free(st->ways);
	free(st->diff);
	free(st);
}

void	ft_solution(t_map *map, t_room *room)
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

void	ft_output_lines(t_str *str)
{
	while (str)
	{
		if (str->line)
			ft_printf("%s\n", str->line);
		str = str->next;
	}
	ft_printf("\n");
}

int		main(void)
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
