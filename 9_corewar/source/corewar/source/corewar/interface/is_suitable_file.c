/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_suitable_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:04:24 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/21 22:09:07 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	is_suitable_file(char *i_path_file)
{
	unsigned		magic;
	int				fd;
	long			file_size;

	file_size = 0;
	if ((fd = open(i_path_file, O_RDONLY)) > -1)
	{
		if (read(fd, &magic, MAGIC_SIZE) != MAGIC_SIZE ||
				number_reverse_mem(magic) != COREWAR_EXEC_MAGIC)
			if (!errno)
				errno = 79;
		if (!errno)
			if ((file_size = (lseek(fd, 0, SEEK_END))) < (long)MIN_SIZE_FILE)
				if (!errno)
					errno = 79;
		close(fd);
	}
	if (!errno && file_size > (long)MAX_SIZE_FILE)
		errno = EFBIG;
	if (errno)
		return (False);
	return (True);
}
