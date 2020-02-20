/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:16:32 by ediego            #+#    #+#             */
/*   Updated: 2020/02/18 10:27:44 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_head(t_str *head)
{
	while (head)
	{
		if (head->line)
			free(head->line);
		free(head);
		head = head->next;
	}
}

void		ft_exit(t_map *map, char *line, int err)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (map->room[i].name)
	{
		while (map->room[i].links)
		{
			tmp = map->room[i].links->next;
			free(map->room[i].links);
			map->room[i].links = tmp;
		}
		free(map->room[i].name);
		i++;
	}
	if (line)
		free(line);
	ft_free_head(map->head);
	free(map);
	if (err == 0)
		write(2, "Error\n", 6);
	if (err == 0)
		exit(0);
}
