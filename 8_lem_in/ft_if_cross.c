/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:32:29 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/05 22:32:30 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_links(t_map *sh_w, int *way)
{
	int		i;
	t_link	*tmp;

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

void		ft_if_cross_2(t_map *map, t_map *sh_w, int *way)
{
	int res;

	res = map->sum_r - 1;
	if (way)
	{
		while (map->room[++res].name)
			sh_w->room[res].name = map->room[res].name;
		ft_move_sh_w(map, sh_w, way);
		ft_finish_move(map, sh_w, way);
		delete_links(sh_w, way);
	}
}

void		ft_if_cross_1(t_map *sh_w, t_w_and_d *var)
{
	t_link	*ls;
	int		res;

	res = 1;
	ls = sh_w->room[sh_w->start].links;
	while (ls && res++)
		ls = ls->next;
	var[var[0].v].ways = (int**)ft_memalloc(sizeof(int*) * (res - 1));
}

void		ft_if_cross(t_map *map, t_map *sh_w, t_w_and_d *var, int *way)
{
	t_map	*tmp;
	int		res;
	int		*wout;

	tmp = ft_copy_map(sh_w);
	ft_if_cross_1(sh_w, var);
	res = 0;
	while (sh_w->room[sh_w->start].links)
	{
		wout = ft_bfs(sh_w, sh_w->room, sh_w->start);
		if (wout[0] == 2147483647)
		{
			free(wout);
			break ;
		}
		var[var[0].v].ways[res++] = wout;
		ft_move_sh_w(sh_w, tmp, wout);
	}
	ft_record_way(var, res);
	ft_find_res(sh_w, var);
	ret_1_2(sh_w, tmp);
	ft_if_cross_2(map, sh_w, way);
	ft_exit(tmp, NULL, 1);
}

int			ft_find_crossing(t_map *sh_w, int *way)
{
	int		i;
	t_link	*tmp;

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
