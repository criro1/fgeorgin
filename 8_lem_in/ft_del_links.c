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

void		ft_do_in_move(t_map *map, int *way, int i)
{
	if (map->room[way[i]].ind_out_room != -1 &&
		map->room[way[i + 1]].ind_out_room != -1)
	{
		way[i + 1] = map->room[way[i + 1]].ind_out_room;
	}
	else if (map->room[way[i]].ind_out_room != -1 &&
		map->room[way[i - 1]].ind_out_room != -1)
	{
		way[i] = map->room[way[i]].ind_out_room;
	}
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

void		ft_del_links_1(t_map *map, int from)
{
	t_link *for_free;

	for_free = map->room[from].links;
	map->room[from].links = map->room[from].links->next;
	free(for_free);
	for_free = NULL;
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
		while (tmp->next && tmp->next->link_num != what)
			tmp = tmp->next;
		for_free = tmp->next;
		if (tmp->next && tmp->next->next)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		free(for_free);
		for_free = NULL;
	}
	else
		ft_del_links_1(map, from);
}
