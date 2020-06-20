/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:21:27 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/05 23:42:14 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_do_tmp(t_link **fin, t_link **tmp, t_w_and_d *st, int stat)
{
	int i;

	i = 0;
	if (stat == 0)
	{
		while (i < st[st[0].v].diff_len)
		{
			tmp[i] = fin[i];
			i++;
		}
	}
	else if (stat == 1)
	{
		while (i < st[st[0].v].diff_len)
		{
			fin[i] = tmp[i];
			i++;
		}
	}
}

void		ft_without_print(t_link **fin, t_w_and_d *st, int *room, int w)
{
	int		j;
	int		res;
	t_link	*tmp[st[st[0].v].diff_len];

	ft_do_tmp(fin, tmp, st, 0);
	res = 0;
	while (w < st[st[0].v].diff_len)
	{
		j = 0;
		w = 0;
		while (j < st[st[0].v].diff_len)
		{
			if (fin[j] && room[j] == st[st[0].v].ways[j][0] + 1)
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
	st[st[0].v].res = res;
}

void		ft_find_res(t_map *map, t_w_and_d *st)
{
	t_link	**fin;
	int		ant;
	int		j;
	int		*room;

	fin = (t_link**)ft_memalloc(sizeof(t_link*) * st[st[0].v].diff_len);
	ant = 1;
	while (ant <= map->num_ants)
	{
		j = 0;
		while (j < st[st[0].v].diff_len)
		{
			if (map->num_ants + 1 - ant > st[st[0].v].diff[j])
			{
				ft_add_ant(&(fin[j]), ant);
				ant++;
			}
			j++;
		}
	}
	room = ft_malloc_roooms(st[st[0].v].diff_len);
	ft_without_print(fin, st, room, 0);
	ft_free_fin(fin, st[st[0].v].diff_len, room);
	st[0].v++;
}

void		ft_finish_move_1(t_map *map, t_map *sh_w)
{
	int i;

	i = map->sum_r;
	while (sh_w->room[i].name)
	{
		if (sh_w->room[i].links)
		{
			sh_w->room[i].links->next =
				sh_w->room[map->room[i].ind_out_room].links;
			sh_w->room[map->room[i].ind_out_room].links = sh_w->room[i].links;
			sh_w->room[i].links = NULL;
		}
		sh_w->room[i].name = NULL;
		i++;
	}
}

void		ft_finish_move(t_map *map, t_map *sh_w, int *way)
{
	int		i;
	t_link	*tmp;

	i = 1;
	while (i <= way[0])
	{
		if (map->room[way[i]].ind_out_room != -1)
		{
			tmp = sh_w->room[way[i]].links;
			while (tmp)
			{
				if (tmp->link_num >= map->sum_r)
					tmp->link_num = map->room[tmp->link_num].ind_out_room;
				tmp = tmp->next;
			}
		}
		i++;
	}
	ft_finish_move_1(map, sh_w);
}
