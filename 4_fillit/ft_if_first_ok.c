/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_first_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:00:24 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/07/08 17:31:46 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_copy(char **dst, char **src, int len)
{
	int		k;

	k = 0;
	while (k < len)
	{
		dst[k] = ft_strcpy(dst[k], src[k]);
		k++;
	}
	return (dst);
}

char	**ft_if_fisrt_ok(char **map, t_tetr *lst, int x, int y)
{
	t_tetr	current;
	int		len;
	char	**doub;

	len = ft_strlen(map[0]);
	current = lst[ft_find_lst(map, len)];
	doub = ft_copy(ft_create_map(len), map, len);
	doub = ft_insert_fig(doub, x, y, current);
	if ((doub = ft_fill_map(doub, 0, 0, lst)) != NULL)
	{
		ft_destroy_map(map, len);
		map = doub;
		return (map);
	}
	else
		map = ft_fill_map(map, x, y + 1, lst);
	return (map);
}
