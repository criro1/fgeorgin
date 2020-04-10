/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_new_player_to_arg_obj.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:15:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/25 19:35:30 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add_file_new_player_to_arg_obj(t_args_obj *m_args,
															char *i_path_file)
{
	t_player	*o_new;

	if (!is_suitable_file(i_path_file))
	{
		save_error_to_log("Inappropriate file", i_path_file);
		return ;
	}
	if ((o_new = new_player(i_path_file, -1)))
		add_to_players(m_args->players, o_new);
		//push_to_plaers(m_args->players, o_new);
	/*
	if (!(o_new = ft_memalloc(sizeof(t_player))))
		save_error_to_log("Player", i_path_file);
	else
	{
		if (!(o_new->file.path = ft_strdup(i_path_file)))
		{
			save_error_to_log("Player->file.path", i_path_file);
			ft_memdel((void**)&o_new);
		}
		else
			add_to_players(m_args->players, o_new);
	}
	*/
}
