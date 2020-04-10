/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_name_com.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 04:52:17 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 05:12:07 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				write_name_fd(t_token_list *tl, int len)
{
	t_token_node	*tmp;
	char			name[len];
	int				i;

	tmp = tl->head;
	while (ft_strcmp(tmp->type, "name"))
		tmp = tmp->next;
	i = ft_strlen(tmp->content) - 2;
	if (i > len)
		ft_exit(tl, "Error");
	i = 0;
	if (tmp->content[1] != '"' && tmp->content[1] != '\0')
		while (tmp->content[i + 1] != '"')
		{
			name[i] = tmp->content[i + 1];
			i++;
		}
	write(tl->fd, &name, i);
	while (i < len + 4)
	{
		write(tl->fd, "\0", 1);
		i++;
	}
}

void				write_comment_fd(t_token_list *tl, int len)
{
	t_token_node	*tmp;
	char			name[len];
	int				i;

	tmp = tl->head;
	while (ft_strcmp(tmp->type, "comment"))
		tmp = tmp->next;
	i = ft_strlen(tmp->content) - 2;
	if (i > len)
		ft_exit(tl, "Error");
	i = 0;
	if (tmp->content[1] != '"' && tmp->content[1] != '\0')
		while (tmp->content[i + 1] != '"')
		{
			name[i] = tmp->content[i + 1];
			i++;
		}
	write(tl->fd, &name, i);
	while (i < len + 4)
	{
		write(tl->fd, "\0", 1);
		i++;
	}
}
