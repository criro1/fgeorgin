/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:54:53 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:34:09 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_boolean	player_parsing_name(t_player *m_player, t_file *i_file)
{
	const char	*file_entry;

	if (!((file_entry = file_get_entry(i_file)) &&
			(m_player->name = ft_strdup(file_entry + MAGIC_SIZE))))
	{
		save_error_to_log("Player: can't allocate mem for name ",
												(char*)file_get_path(i_file));
		return (False);
	}
	return (True);
}

static t_boolean	player_parsing_comment(t_player *m_player, t_file *i_file)
{
	const char	*file_entry;

	if (!((file_entry = file_get_entry(i_file)) &&
			(m_player->comment = ft_strdup(file_entry + MAGIC_SIZE +
									PROG_NAME_LENGTH + CODE_SIZE + NULL_SIZE))))
	{
		save_error_to_log("Player: can't allocate mem for comment ",
												(char*)file_get_path(i_file));
		return (False);
	}
	return (True);
}

static t_boolean	player_parsing_execcode(t_player *m_player, t_file *i_file)
{
	const char	*file_entry;

	if (!(file_entry = file_get_entry(i_file)))
		return (False);
	ft_memcpy(m_player->mem_champion, file_entry + HEDER_SIZE,
							file_get_size(i_file, "byte") - HEDER_SIZE);
	return (True);
}

static void			player_parsing_size_bytes(t_player *m_player)
{
	m_player->size_bytes = file_get_size(m_player->file, "byte") - HEDER_SIZE;
}

t_boolean			player_parsing(t_player *m_player)
{
	if (file_has_entry(m_player->file))
	{
		if (!((player_parsing_name(m_player, m_player->file) &&
				player_parsing_comment(m_player, m_player->file) &&
					player_parsing_execcode(m_player, m_player->file))))
			return (False);
		player_parsing_size_bytes(m_player);
	}
	else
	{
		save_error_to_log("Player : No Entry ",
									(char*)file_get_path(m_player->file));
		return (False);
	}
	return (True);
}
