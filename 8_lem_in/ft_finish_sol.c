/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:27:43 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/07 14:27:46 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_var(t_w_and_d *var)
{
	int i;
	int j;

	i = 0;
	while (i < var[0].v)
	{
		j = 0;
		while (j < var[i].diff_len)
		{
			free(var[i].ways[j]);
			j++;
		}
		free(var[i].ways);
		free(var[i].diff);
		i++;
	}
}

void		ft_finish_sol(t_map *map, t_w_and_d *var)
{
	int i;
	int min;
	int v;

	i = 0;
	min = 2147483647;
	v = 0;
	while (var[i].res != 0 && var[i].ways && var[i].ways[0])
	{
		if (var[i].res != 0 && var[i].res < min)
		{
			min = var[i].res;
			v = var[i].num;
		}
		i++;
	}
	ft_ants_to_ways(map, &(var[v]));
	ft_free_var(var);
}
