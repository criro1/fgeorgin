/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:31:03 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/11 20:10:17 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	If there is no player memory it means you need to load from the file,
**	otherwise the player is already checked and already initialized.
*/

int		init_player(t_player *m_player)
{
	if (!*m_player->mem_champion)
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
	}
	return (PL_SUCCESS);
}
