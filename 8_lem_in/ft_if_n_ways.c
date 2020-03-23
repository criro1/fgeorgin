/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_n_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:38:01 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/22 18:50:49 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_way_n_wout(int *way, int *wout)
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

void		ret_1_2(t_map *map, t_map *sh_w)
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

void		ft_del_links(t_map *map, int from, int what)
{
	t_link *tmp;
	t_link *for_free;

	if (map->room[from].links->link_num != what)
	{
		tmp = map->room[from].links;
		if (tmp->next == NULL)
			return ;
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

void		ft_del_1_2(t_map *map, int *way, int *wout)
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

// void	ft_do_minus_1(t_map *map, int *way)
// {
// 	int i;
// 	t_link *tmp;

// 	i = way[0] + 1;
// 	while (i > 1)
// 	{
// 		tmp = map->room[way[i]].links;
// 		while (tmp->link_num != way[i - 1])
// 			tmp = tmp->next;
// 		tmp->weight = -1;
// 		i--;
// 	}
// }

void		ft_if_n_ways(t_map *map, t_map *sh_w, t_map *tmp)
{
	int *way;
	int *wout;

	while (map->room[map->start].links)
	{
		way = ft_bfs(map, map->room, map->start);
		if (way[0] == 2147483647)
		{
			free(way);
			break ;
		}
		ft_move_sh_w(map, sh_w, way);
		// ft_do_minus_1(map, way);
		while (map->room[map->start].links)
		{
			wout = ft_bfs(map, map->room, map->start);
			if (ft_way_n_wout(way, wout))
			{
				ret_1_2(map, sh_w);
				ft_del_1_2(map, way, wout);
				ret_1_2(map, tmp);//obuouhh
				free(wout);
				continue ;
			}
			// else
			// 	ft_if_stop(map, sh_w, way, wout);
			// ft_move_sh_w(map, sh_w, wout);
			if (wout[0] != 2147483647)
				ft_move_sh_w(map, tmp, wout); //asdsad
			else
			{
				free(wout);
				break ;
			}
			free(wout);

		}
		free(way);
		// ret_1_2(map, sh_w);
		ret_1_2(map, tmp); //asddiassa
	}
	ret_1_2(map, sh_w);
}
