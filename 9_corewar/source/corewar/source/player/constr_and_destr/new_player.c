/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:16:27 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 12:59:24 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*new_player(char *i_path, int i_order)
{
	t_player *o_new;

	if (!(o_new = ft_memalloc(sizeof(t_player))))
		save_error_to_log("Player", i_path);
	else
	{
		if (!(o_new->file = new_file(i_path)))
		{
			save_error_to_log("Can't created t_file", i_path);
			ft_memdel((void**)&o_new);
		}
		else
		{
			o_new->order = ((i_order < 0) ? 0 : i_order);
		}
	}
	return (o_new);
}
