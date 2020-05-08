/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:09:47 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 19:57:40 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define BUFF_SIZE_FL	1024

static void	copy_entry(t_file *m_file)
{
	unsigned char	*entry;
	int				fd;

	entry = m_file->entry;
	fd = m_file->fd;
	if (read(fd, entry, m_file->size) < 0)
	{
		perror("Can't load file");
		exit(EXIT_FAILURE);
	}
}

t_boolean	load_file(t_file *m_file)
{
	long	size_file;

	size_file = file_get_size(m_file, "byte");
	if (size_file && (m_file->entry = ft_memalloc(size_file)))
	{
		if (file_open(m_file, O_RDONLY))
		{
			copy_entry(m_file);
			file_close(m_file);
		}
	}
	if (errno)
	{
		save_error_to_log("File", m_file->path);
		return (False);
	}
	return (size_file ? True : False);
}
