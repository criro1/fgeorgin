/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:31:03 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/31 10:55:25 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		init_player(t_player *m_player)
{
	if (!load_file(m_player->file))
	{
		save_error_to_log("Player: Can't open file",
										(char*)file_get_path(m_player->file));
		return (PL_LOADFILE_ERROR);
	}
	if (!(player_validation(m_player)))
		return (PL_VALIDATION_ERROR);
	if (!(player_parsing(m_player)))
		return (PL_PARSING_ERROR);
	destroy_file(&m_player->file);
	return (PL_SUCCESS);
}
