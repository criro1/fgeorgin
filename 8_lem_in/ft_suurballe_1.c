/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suurballe_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:44:47 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/08 15:23:26 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_dup_link_1(t_room *cur, t_link *iter, int end, int start)
{
	if (cur[end].ind_out_room != -1)
	{
		iter = cur[cur[end].ind_out_room].links;
		while (iter && iter->link_num != start)
			iter = iter->next;
		if (iter)
			iter->link_num = end;
	}
}

void		ft_dup_link(t_map *map, int end, int start, t_room *cur)
{
	t_link *iter;

	iter = cur[end].links;
	while (iter && iter->link_num != cur[start].num)
		iter = iter->next;
	if (iter && cur[start].ind_out_room != -1)
	{
		iter->link_num = cur[start].ind_out_room;
	}
	else if (!iter && cur[start].ind_out_room != -1)
	{
		make_link(map, cur[end].num, cur[start].ind_out_room);
	}
	else
	{
		make_link(map, cur[end].num, cur[start].num);
	}
	ft_dup_link_1(cur, iter, end, start);
}

int			ft_if_in_way(int *res, int num)
{
	int i;

	i = 1;
	while (i < res[0] + 1)
	{
		if (res[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void		ft_make_dup_link(t_map *map, int *way, int *res)
{
	int		count;
	t_room	*cur;

	cur = map->room;
	count = way[0] + 1;
	while (count >= 2)
	{
		if (way[count] == map->end || ft_if_in_way(res, way[count]) == 0)
			ft_dup_link(map, way[count], way[count - 1], cur);
		count--;
	}
}
