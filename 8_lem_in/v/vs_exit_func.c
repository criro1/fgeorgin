/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_exit_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:16:32 by ediego            #+#    #+#             */
/*   Updated: 2020/03/08 17:05:03 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		vs_free_head(t_str *head)
{
	while (head)
	{
		if (head->line)
			free(head->line);
		free(head);
		head = head->next;
	}
}

void		vs_exit(t_vs *vs, char *line, int err)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (vs->map->room[i].name)
	{
		while (vs->map->room[i].links)
		{
			tmp = vs->map->room[i].links->next;
			free(vs->map->room[i].links);
			vs->map->room[i].links = tmp;
		}
		free(vs->map->room[i].name);
		free(vs->map->room[i].name_ant);
		i++;
	}
	if (line)
		free(line);
	vs_free_head(vs->map->head);
	free(vs->map);
	free(vs);
	if (err == 0)
		write(2, "ERROR\n", 6);
	if (err == 0)
		exit(0);
}
