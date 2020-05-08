/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:02:19 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/21 21:57:10 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	validation_magic(unsigned char **m_mem)
{
	if (number_reverse_mem(*(unsigned*)(*m_mem)) == COREWAR_EXEC_MAGIC)
	{
		*m_mem += MAGIC_SIZE;
		return (True);
	}
	else
		ft_dprintf(2, "Player: invalid magic:");
	return (False);
}

t_boolean	validation_champ_name(unsigned char **m_mem)
{
	unsigned char	*mem_player;
	unsigned char	*end_name;

	mem_player = *m_mem;
	end_name = mem_player + PROG_NAME_LENGTH;
	if (*(unsigned*)end_name)
	{
		ft_dprintf(2, "Player: invalid name player (no NULL):");
		return (False);
	}
	while (*mem_player)
		++mem_player;
	while (mem_player < end_name)
	{
		if (*mem_player)
		{
			ft_dprintf(2, "Player: invalid name player:");
			return (False);
		}
		++mem_player;
	}
	*m_mem = end_name + 4;
	return (True);
}

t_boolean	validation_exc_champ_size(unsigned char **m_mem, size_t size_byte)
{
	unsigned	exec_mem_size;

	exec_mem_size = number_reverse_mem(*(unsigned*)(*m_mem));
	if (exec_mem_size + HEDER_SIZE != size_byte)
	{
		ft_dprintf(2, "Player: header contains invalid executable code size: ");
		return (False);
	}
	*m_mem += 4;
	return (True);
}

t_boolean	validation_comment(unsigned char **m_mem)
{
	unsigned char	*mem_player;
	unsigned char	*end_comment;

	mem_player = *m_mem;
	end_comment = mem_player + COMMENT_LENGTH;
	if (*(unsigned*)end_comment)
	{
		ft_dprintf(2, "Player: invalid comment player (no NULL):");
		return (False);
	}
	while (*mem_player)
		++mem_player;
	while (mem_player < end_comment)
	{
		if (*mem_player)
		{
			ft_dprintf(2, "Player: invalid comment:");
			return (False);
		}
		++mem_player;
	}
	*m_mem = end_comment + 4;
	return (True);
}

t_boolean	player_validation(t_player *m_pl)
{
	unsigned char	*mem;

	if (m_pl->file && file_has_entry(m_pl->file))
	{
		mem = (unsigned char*)file_get_entry(m_pl->file);
		if (validation_magic(&mem) && validation_champ_name(&mem) &&
			validation_exc_champ_size(&mem, file_get_size(m_pl->file, "byte"))
			&& validation_comment(&mem))
			return (True);
		ft_dprintf(2, "%s\n", file_get_path(m_pl->file));
	}
	else
		save_error_to_log("Player: validation", "No file or entry");
	return (False);
}
