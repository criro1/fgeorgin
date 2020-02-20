/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:11:22 by ediego            #+#    #+#             */
/*   Updated: 2020/02/18 20:04:36 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		close1(t_vs *vs)
{
	int		i;
	t_link	*tmp;

	if (vs && vs->win)
		mlx_destroy_window(vs->ptr, vs->win);
	i = 0;
	while (vs->map->room[i].name)
	{
		ft_strdel(&vs->map->room[i].name_ant);
		while (vs->map->room[i].links)
		{
			tmp = vs->map->room[i].links->next;
			free(vs->map->room[i].links);
			vs->map->room[i].links = tmp;
		}
		free(vs->map->room[i].name);
		i++;
	}
	free(vs->map);
	free(vs);
	exit(0);
	return (0);
}

void	vs_read_input(t_map *map, int i)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (map->data == 0 && ft_strchr("0123456789-", line[0]))
			vs_number_of_ants(map, line);
		else if (line[0] != '\0' && line[0] == '#')
			vs_sharp(map, &line, &i);
		else if (line[0] != '\0' && line[0] != 'L'
				&& (map->data == 3 || ft_strchr(line, '-')))
			vs_the_links(map, line);
		else if (line[0] != '\0' && line[0] != 'L'
				&& (map->data == 1 || map->data == 2))
			vs_the_room(map, line, 2, &i);
		else if (line[0] == '\0')
			break ;
		else
			ft_exit(map, line, 1);
		free(line);
	}
	if (map->data != 3 || map->ok_s != 'O' || map->ok_e != 'O' || i < 2)
		ft_exit(map, NULL, 1);
}

int		main(void)
{
	t_vs	*vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))) ||
	!(vs->map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit(1);
	vs_read_input(vs->map, 0);
	vs->ptr = mlx_init();
	vs->win = mlx_new_window(vs->ptr, 1200, 1200, "map-in");
	vs_scale_scene(vs);
	vs->scale = 1.0;
	vs_scene(vs);
	mlx_hook(vs->win, 17, 4, close1, vs);
	mlx_hook(vs->win, 2, 1, key_press, vs);
	mlx_loop(vs->ptr);
	return (0);
}
