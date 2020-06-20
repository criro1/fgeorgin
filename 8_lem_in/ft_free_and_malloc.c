/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:36:00 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/13 21:36:02 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_fin(t_link **fin, int diff_len, int *room)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (i < diff_len)
	{
		while (fin[i])
		{
			tmp = fin[i]->next;
			free(fin[i]);
			fin[i] = tmp;
		}
		i++;
	}
	free(fin);
	free(room);
}

void		ft_free_st(t_w_and_d *st)
{
	int i;

	i = 0;
	while (i < st->diff_len)
	{
		free(st->ways[i]);
		i++;
	}
	free(st->ways);
	free(st->diff);
	free(st);
}

t_map		*ft_copy_map(t_map *map)
{
	int		i;
	t_map	*sh_w;

	sh_w = (t_map*)ft_memalloc(sizeof(t_map));
	i = 0;
	while (map->room[i].name)
	{
		sh_w->room[i].name = ft_strdup(map->room[i].name);
		sh_w->room[i].num = map->room[i].num;
		sh_w->room[i].x = map->room[i].x;
		sh_w->room[i].y = map->room[i].y;
		i++;
	}
	sh_w->start = map->start;
	sh_w->end = map->end;
	sh_w->sum_r = map->sum_r;
	sh_w->num_ants = map->num_ants;
	return (sh_w);
}

int			*ft_malloc_roooms(int j)
{
	int *room;

	room = (int*)ft_memalloc(sizeof(int) * j);
	while (j--)
		room[j] = 2;
	return (room);
}

void		ft_output_lines(t_str *str)
{
	while (str)
	{
		if (str->line)
			ft_printf("%s\n", str->line);
		str = str->next;
	}
	ft_printf("\n");
}
