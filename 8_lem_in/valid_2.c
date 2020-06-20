/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_valid_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:13:01 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/24 16:09:56 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_find_num(t_room *room, char *arr_n)
{
	int i;

	i = -1;
	while (room[++i].name)
	{
		if (room[i].name[0] == arr_n[0] && room[i].name[1] == arr_n[1])
			if (!(ft_strcmp(room[i].name, arr_n)))
				return (i);
	}
	return (-1);
}

void		make_link(t_map *map, int n0, int n1)
{
	t_link	*l;
	t_link	*temp;

	l = (t_link*)ft_memalloc(sizeof(t_link));
	l->link_num = n1;
	l->next = NULL;
	if (map->room[n0].links == NULL)
	{
		map->room[n0].links = l;
		return ;
	}
	temp = map->room[n0].links;
	while (map->room[n0].links->next != NULL)
		map->room[n0].links = map->room[n0].links->next;
	map->room[n0].links->next = l;
	map->room[n0].links = temp;
}

int			ft_if_l(t_map *map, int n0, int n1)
{
	t_link *l;

	l = map->room[n0].links;
	while (l)
	{
		if (l->link_num == n1)
			return (0);
		l = l->next;
	}
	return (1);
}

int			ft_coord(t_map *map, char *s1, char *s2)
{
	int i;
	int x;
	int y;

	x = ft_atoi(s1);
	y = ft_atoi(s2);
	i = 0;
	while (map->room[i].name)
	{
		if (map->room[i].x == x && map->room[i].y == y)
			return (0);
		i++;
	}
	return (1);
}
