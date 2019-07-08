/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:06:04 by forange-          #+#    #+#             */
/*   Updated: 2019/07/08 17:01:30 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_lst(char **map, int size)
{
	char	let;
	int		i;
	int		j;

	let = 'A' - 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] > let)
				let = map[i][j];
			j++;
		}
		i++;
	}
	if (let == 'A' - 1)
		return (0);
	return (let - 'A' + 1);
}

int		ft_check_fig(int x, int y, t_tetr fig, char **map)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(map[0]);
	while (i < 4)
	{
		if (fig.col[i] + y >= len)
			return (2);
		if (fig.row[i] + x >= len)
			return (3);
		if (map[fig.row[i] + x][fig.col[i] + y] != '.')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_insert_fig(char **map, int x, int y, t_tetr current)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[current.row[i] + x][current.col[i] + y] = current.letter;
		i++;
	}
	return (map);
}

char	**ft_fill_map(char **map, int x, int y, t_tetr *lst)
{
	t_tetr	current;
	int		len;

	len = ft_strlen(map[0]);
	current = lst[ft_find_lst(map, len)];
	if (current.letter == '\0')
		return (map);
	if (ft_check_fig(x, y, current, map) == 0)
		map = ft_if_fisrt_ok(map, lst, x, y);
	else if (ft_check_fig(x, y, current, map) == 1)
		map = ft_fill_map(map, x, y + 1, lst);
	else if (ft_check_fig(x, y, current, map) == 2)
		map = ft_fill_map(map, x + 1, 0, lst);
	else if (ft_check_fig(x, y, current, map) == 3 && current.letter == 'A')
	{
		ft_destroy_map(map, len);
		map = ft_create_map(len + 1);
		map = ft_fill_map(map, 0, 0, lst);
	}
	else
	{
		ft_destroy_map(map, len);
		return (NULL);
	}
	return (map);
}

char	**ft_solver(t_tetr *lst)
{
	char **map;

	map = ft_create_map(ft_first_approx(lst));
	return (ft_fill_map(map, 0, 0, lst));
}
