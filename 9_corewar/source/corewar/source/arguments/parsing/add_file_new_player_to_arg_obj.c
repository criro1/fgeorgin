/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_new_player_to_arg_obj.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:15:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:04:41 by wmaykit          ###   ########.fr       */
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
}
