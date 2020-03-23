/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:46:43 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/25 19:34:51 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_if_no_way(t_map *map, int *way)
{
	if (way[0] == 2147483647)
	{
		free(way);
		ft_exit(map, NULL, 0);
	}
	else
	{
		free(way);
		ft_output_lines(map->head);
	}
}

void	ft_do_minus_1(t_map *map, int *way)
{
	int i;
	t_link *tmp;

	i = way[0] + 1;
	while (i > 1)
	{
		tmp = map->room[way[i]].links;
		if (tmp != NULL)
		{
			while (tmp && tmp->link_num != way[i - 1])
				tmp = tmp->next;
			if (tmp)
				tmp->weight = -1;
		}
		i--;
	}
}

int			ft_find_crossing(t_map *sh_w, int *way)
{
	int i;
	t_link *tmp;

	if (!way)
		return (0);
	i = way[0] + 1;
	while (i >= 2)
	{
		tmp = sh_w->room[way[i]].links;
		while (tmp)
		{
			if (tmp->link_num == way[i - 1])
				return (1);
			tmp = tmp->next;
		}
		i--;
	}
	return (0);
}

void		ft_without_print(t_map * map, t_link **fin, t_w_and_d *st, int *room)
{
	map->ok_e = 1;
	int		w;
	int		j;
	int		res;
	t_link	*tmp[st->diff_len];

	ft_do_tmp(fin, tmp, st, 0);
	res = 0;
	w = 0;
	while (w < st->diff_len)
	{
		j = 0;
		w = 0;
		while (j < st->diff_len)
		{
			if (fin[j] && room[j] == st->ways[j][0] + 1)
				fin[j] = fin[j]->next;
			else
				room[j]++;
			if (!fin[j])
				w++;
			j++;
		}
		res++;
	}
	ft_do_tmp(fin, tmp, st, 1);
	st->res = res;
}

void        ft_find_res(t_map *map, t_w_and_d *st)
{
    t_link  **fin;
    int     ant;
    int     j;
    int     *room;
    int     need;
    fin = (t_link**)ft_memalloc(sizeof(t_link*) * st->diff_len);
    ant = 1;
    need = 1;
    j = 0;
    while (map->num_ants + 1 - need > st->diff[j])
    {
        need++;
        j++;
    }
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
			else
				break ;
            j++;
        }
    }
    j = st->diff_len;
    room = ft_malloc_roooms(j);
    ft_without_print(map, fin, st, room);
    ft_free_fin(fin, st->diff_len, room);
}

int			ft_bef(t_w_and_d *var, int j)
{
	int res;
	int	curr;

	res = 0;
	curr = var->ways[j][0];
	j--;
	while (j > 0)
	{
		res = res + (curr - var->ways[j][0]);
		j--;
	}
	return (res);
}

void		ft_record_way(t_w_and_d *var, int i)
{
	int j;

	var->num = var[0].v;
	var->diff = (int*)ft_memalloc(sizeof(int) * i);
	j = 1;
	while (j < i)
	{
		var->diff[j] = /*var->ways[j][0] - var->ways[j - 1][0] +*/ ft_bef(var, j);
		j++;
	}
	var->diff_len = j;
	var[0].v++;
}

void		delete_links(t_map *sh_w, int *way)
{
	int	i;
	t_link *tmp;

	i = way[0] + 1;
	while (i >= 2)
	{
		tmp = sh_w->room[way[i]].links;
		while (tmp)
		{
			if (tmp->link_num == way[i - 1])
			{
				ft_del_links(sh_w, way[i - 1], way[i]);
				ft_del_links(sh_w, way[i], way[i - 1]);
			}
			tmp = tmp->next;
		}
		i--;
	}
}

void		ft_de_suurballe(t_map *map)
{
	t_room *cur;
	t_link *iter;
	t_link *swap;
	int i;

	cur = map->room;
	map->tmp = map->sum_r;
	iter = cur[map->end].links;
	while (cur[iter->link_num].ind_out_room == -1)
		iter = iter->next;
	iter->link_num = cur[iter->link_num].num;
	while (cur[map->tmp].name)
	{
		iter = cur[map->tmp].links;
		while (iter->link_num != cur[map->tmp].num)
			iter = iter->next;
		iter->link_num = cur[cur[iter->link_num].links->link_num].num;
		swap = cur[cur[map->tmp].num].links;
		cur[cur[map->tmp].num].links = cur[map->tmp].links;
		cur[map->tmp].links = swap;
		map->tmp++;
	}
	i = map->sum_r;
	while (map->room[i].name)
	{
		while (map->room[i].links)
		{
			iter = map->room[i].links->next;
			free(map->room[i].links);
			map->room[i].links = iter;
		}
		free(map->room[i].name);
		map->room[i].name = NULL;
		i++;
	}
}

void		ft_if_cross(t_map *map, t_map *sh_w, t_w_and_d *var, int *way)
{
	t_link	*ls;
	t_map	*tmp;
	int res;
	int *wout;

	res = 1;
	ls = sh_w->room[sh_w->start].links;
	while (ls && res++)
		ls = ls->next;
	tmp = ft_copy_map(sh_w);
	var[var[0].v].ways = (int**)ft_memalloc(sizeof(int*) * (res - 1));
	res = 0;
	while (sh_w->room[sh_w->start].links)
	{
		wout = ft_bfs(sh_w, sh_w->room, sh_w->start);
		var[var[0].v].ways[res++] = wout;
		ft_move_sh_w(sh_w, tmp, wout);
	}
	ft_record_way(&(var[var[0].v]), res);//записываем в var пути
	ft_find_res(sh_w, &(var[var[0].v - 1]));//находим кол-во путей для данного случая
	ret_1_2(sh_w, tmp);
	if (way)
	{
		ft_move_sh_w(map, sh_w, way);
		delete_links(sh_w, way);//удаляем связи которые повторились
	}
	ft_exit(tmp, NULL, 1);
}

void		ft_free_var(t_w_and_d *var)
{
	int i;
	int j;

	i = 0;
	while (i < var[0].v)
	{
		j = 0;
		while (j < var[i].diff_len)
		{
			free(var[i].ways[j]);
			j++;
		}
		free(var[i].ways);
		free(var[i].diff);
		i++;
	}
}
void		ft_finish_sol(t_map *map, t_w_and_d *var)
{
	int i;
	int min;
	int v;

	i = 0;
	min = 2147483647;
	v = 0;
	while (var[i].res != 0 && var[i].ways && var[i].ways[0])
	{
		if (var[i].res != 0 && var[i].res < min)
		{
			min = var[i].res;
			v = var[i].num;
		}
		i++;
	}
	ft_ants_to_ways(map, &(var[v]));
	ft_free_var(var);
}

void	ft_do_0_var(t_w_and_d *var)
{
	int i;

	i = 0;
	while (i < 100)
	{
		var[i].res = 0;
		i++;
	}
}

void		ft_solution(t_map *map)
{
	int			*way;
	t_map		*sh_w;
	t_w_and_d	var[100];

	ft_do_0_var(var);
	sh_w = ft_copy_map(map);
	way = NULL;
	while (map->room[map->start].links && !ft_find_crossing(sh_w, way))
	{
		way = ft_bfs(map, map->room, map->start);
		if (way[0] == 2147483647)// это значит, что кончились пути и нужно закончить поиск
			break ;
		if (ft_find_crossing(sh_w, way) == 1)//находим пересечения путей, который нашел бфс и sh_w(copy map)
			ft_if_cross(map, sh_w, var, way);
		else
		{
			ft_move_sh_w(map, sh_w, way);//перекидываем связи прямого пути бфс в sh_w
			ft_suurballe(map, way);
		}
		free(way);
	}
	ft_if_cross(map, sh_w, var, NULL);
	ft_exit(sh_w, NULL, 1);
	ft_finish_sol(map, var);
}

void 	ft_init_map(t_map *map)
{
	int count;
	t_room *room;

	count = 0;
	room = map->room;
	while (room[count].name)
		count++;
	map->sum_r = count;
}

int			main(void)
{
	t_map	*map;
	int		*val;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->out = (t_str*)ft_memalloc(sizeof(t_str));
	map->head = map->out;
	ft_valid(map, 0);
	ft_init_map(map); // add ediego
	val = ft_bfs(map, map->room, map->start);
	ft_if_no_way(map, val);
	ft_solution(map);
	ft_exit(map, NULL, 1);
	return (0);
}
