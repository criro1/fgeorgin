/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_to_ways.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:37:35 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/12/08 19:37:37 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_do_tmp_1(t_link **fin, t_link **tmp, t_w_and_d *st, int stat)
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

void		ft_output(t_map *map, t_link *fin_j, int room, int *way)
{
	while (fin_j && fin_j->link_num <= map->num_ants
		&& (room <= way[0] + 1 && room >= 2))
	{
		ft_printf("L%d-%s ", fin_j->link_num, map->room[way[room]].name);
		fin_j = fin_j->next;
		room--;
	}
}

void		ft_print_ants(t_map *map, t_link **fin, t_w_and_d *st, int *room)
{
	int		j;
	int		res;
	t_link	*tmp[st->diff_len];

	ft_do_tmp_1(fin, tmp, st, 0);
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
	ft_do_tmp_1(fin, tmp, st, 1);
}

void		ft_add_ant(t_link **fin_j, int ant)
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

void		ft_ants_to_ways(t_map *map, t_w_and_d *st)
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
			else
				break ;
			j++;
		}
	}
	room = ft_malloc_roooms(st->diff_len);
	ft_print_ants(map, fin, st, room);
	ft_free_fin(fin, st->diff_len, room);
}
