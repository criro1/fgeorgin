/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:29:59 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/07 14:30:09 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_bef(t_w_and_d *var, int j)
{
	int res;
	int	curr;

	res = 0;
	curr = var[var[0].v].ways[j][0];
	while (j > 0)
	{
		j--;
		res = res + (curr - var[var[0].v].ways[j][0]);
	}
	return (res);
}

void		ft_record_way(t_w_and_d *var, int i)
{
	int j;

	var[var[0].v].num = var[0].v;
	var[var[0].v].diff = (int*)ft_memalloc(sizeof(int) * i);
	j = 1;
	while (j < i)
	{
		var[var[0].v].diff[j] = ft_bef(var, j);
		j++;
	}
	var[var[0].v].diff_len = j;
}
