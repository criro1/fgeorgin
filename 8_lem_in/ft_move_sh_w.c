/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sh_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:30:22 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/13 21:30:25 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_move_1_con(t_link *tmp_sh, t_link *tmp)
{
	while (tmp_sh->next != NULL)
		tmp_sh = tmp_sh->next;
	tmp_sh->next = tmp->next;
	tmp->next = tmp->next->next;
	tmp_sh->next->next = NULL;
}

void		ft_move_sh_w_1(t_map *map, t_map *sh_w, int *way, int i)
{
	t_link	*tmp;
	t_link	*tmp_sh;

	tmp = map->room[way[i]].links;
	while (tmp->next && tmp->next->link_num != way[i + 1])
		tmp = tmp->next;
	tmp_sh = sh_w->room[way[i]].links;
	if (tmp_sh && tmp_sh->next)
		ft_move_1_con(tmp_sh, tmp);
	else if (tmp_sh && !tmp_sh->next)
	{
		sh_w->room[way[i]].links->next = tmp->next;
		tmp->next = tmp->next->next;
		sh_w->room[way[i]].links->next->next = NULL;
	}
	else
	{
		sh_w->room[way[i]].links = tmp->next;
		tmp->next = tmp->next->next;
		sh_w->room[way[i]].links->next = NULL;
	}
}

void		ft_move_sh_w_2(t_map *map, t_map *sh_w, int *way, int i)
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

void		ft_move_sh_w_3(t_map *map, t_map *sh_w, int *way, int i)
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

void		ft_move_sh_w(t_map *map, t_map *sh_w, int *way)
{
	int i;

	i = 1;
	while (i <= way[0])
	{
		ft_do_in_move(map, way, i);
		if (map->room[way[i]].links && map->room[way[i]].links
			->link_num != way[i + 1] && map->room[way[i]].links->next &&
			map->room[way[i]].links->next->link_num != way[i + 1])
			ft_move_sh_w_1(map, sh_w, way, i);
		else if (map->room[way[i]].links && map->room[way[i]].links->
			link_num != way[i + 1] && map->room[way[i]].links->next &&
			map->room[way[i]].links->next->link_num == way[i + 1])
			ft_move_sh_w_2(map, sh_w, way, i);
		else if (map->room[way[i]].links &&
			map->room[way[i]].links->link_num == way[i + 1])
			ft_move_sh_w_3(map, sh_w, way, i);
		ft_do_in_move(map, way, i);
		i++;
	}
}
