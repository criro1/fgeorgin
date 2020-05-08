/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_unpack_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:05:48 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 12:40:38 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	*player_unpak_name(unsigned char *o_iter, t_player *i_player)
{
	int		size_name;

	size_name = 0;
	ft_memcpy(&size_name, o_iter, 4);
	o_iter += 4;
	if (!(i_player->name = ft_memalloc(size_name + 1)))
		return (NULL);
	ft_memcpy(i_player->name, o_iter, size_name);
	return (o_iter + size_name);
}

static void	*player_unpak_comment(unsigned char *o_iter, t_player *i_player)
{
	int		size_comment;

	size_comment = 0;
	ft_memcpy(&size_comment, o_iter, 4);
	o_iter += 4;
	if (!(i_player->comment = ft_memalloc(size_comment + 1)))
		return (NULL);
	ft_memcpy(i_player->comment, o_iter, size_comment);
	return (o_iter + size_comment);
}

static void	*player_unpak_mem(unsigned char *o_iter, t_player *i_player)
{
	int		size_mem;

	size_mem = 0;
	ft_memcpy(&size_mem, o_iter, 4);
	o_iter += 4;
	ft_memcpy(i_player->mem_champion, o_iter, size_mem);
	i_player->size_bytes = size_mem;
	return (o_iter + size_mem);
}

t_player	*network_unpack_player(t_pack_net *i_pakage)
{
	t_player		*o_new;
	unsigned char	*iterator;
	unsigned char	*end;

	if (!(o_new = ft_memalloc(sizeof(t_player))))
		return (NULL);
	iterator = i_pakage->data;
	end = ((unsigned char *)i_pakage->data) + i_pakage->size;
	if (!(iterator = player_unpak_name(iterator, o_new)) || iterator > end)
	{
		destroy_player(&o_new);
		return (NULL);
	}
	if (!(iterator = player_unpak_comment(iterator, o_new)) || iterator > end)
	{
		destroy_player(&o_new);
		return (NULL);
	}
	if ((unsigned char *)player_unpak_mem(iterator, o_new) > end)
	{
		destroy_player(&o_new);
		return (NULL);
	}
	return (o_new);
}
