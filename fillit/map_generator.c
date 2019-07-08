/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:13:23 by forange-          #+#    #+#             */
/*   Updated: 2019/07/08 17:02:03 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_first_approx(t_tetr *mas)
{
	int		count;

	count = 0;
	while (mas[count].letter)
		count++;
	if (count == 1 || count == 4 || count == 9 || count == 16 || count == 25)
		return (ft_sqrt(count * 4));
	return (ft_sqrt(count * 4) + 1);
}

char		**ft_create_map(size_t size)
{
	char	**map;
	size_t	i;

	i = 0;
	map = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * size + 1);
		map[i] = (char*)ft_memset(map[i], '.', size);
		map[i][size] = '\0';
		i++;
	}
	return (map);
}

void		ft_destroy_map(char **map, int len)
{
	while (len--)
		free(map[len]);
	free(map);
}

void		ft_print_map(char **map)
{
	int len;
	int i;
	int j;

	i = 0;
	len = ft_strlen(map[0]);
	while (i < len)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
