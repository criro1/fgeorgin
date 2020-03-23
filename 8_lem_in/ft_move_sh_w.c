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

void		ft_move_sh_w_1(t_map *map, t_map *sh_w, int *way, int i)
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
		tmp->next = tmp->next->next;
		tmp_sh->next->next = NULL;
	}
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

void	ft_way_minus(t_map *map, int *way)
{
	int i;
	t_link *tmp;

	i = 1;
	while (i <= way[0])
	{
		tmp = map->room[way[i]].links;
		if (tmp != NULL) // right?
		{
			while (tmp && tmp->link_num != way[i + 1])
				tmp = tmp->next;
			if (tmp)
				tmp->weight = -1;
		}
		i++;
	}
}

void		ft_sort_weight(t_map *map, int *way)
{
	t_link	*tmp;
	t_link	*tmp_minus;
	t_link	*head;
	int i;

	i = 1;
	while (i <= way[0])
	{
		tmp_minus = NULL;
		head = NULL;
		tmp = map->room[way[i]].links;
		while (tmp)
		{
			if (tmp && tmp->next && tmp->next->weight == -1)
			{
				if (tmp_minus)
				{
					tmp_minus->next = tmp->next;
					tmp_minus = tmp_minus->next;
				}
				else
				{
					tmp_minus = tmp->next;
					if (head == NULL)
						head = tmp_minus;
				}
			}
			tmp = tmp->next;
		}
		i++;
		tmp = head;
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = map->room[way[i]].links;
			map->room[way[i]].links = head;
		}
	}
}


void		ft_move_sh_w(t_map *map, t_map *sh_w, int *way)
{
	int i;

	i = 1;
	while (i <= way[0])
	{
		if (map->room[way[i]].links->link_num != way[i + 1] &&
			map->room[way[i]].links->next &&
			map->room[way[i]].links->next->link_num != way[i + 1])
		{
			ft_move_sh_w_1(map, sh_w, way, i);
		}
		else if (map->room[way[i]].links->link_num != way[i + 1] &&
			map->room[way[i]].links->next &&
			map->room[way[i]].links->next->link_num == way[i + 1])
		{
			ft_move_sh_w_2(map, sh_w, way, i);
		}
		else if (map->room[way[i]].links->link_num == way[i + 1])
			ft_move_sh_w_3(map, sh_w, way, i);
		i++;
	}
}
