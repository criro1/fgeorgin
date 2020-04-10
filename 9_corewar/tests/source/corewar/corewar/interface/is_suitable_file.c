/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_suitable_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:04:24 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/26 22:17:18 by wmaykit          ###   ########.fr       */
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
				errno = EFTYPE;
		if (!errno)
			if ((file_size = (lseek(fd, 0, SEEK_END))) < (long)MIN_SIZE_FILE)
				if (!errno)
					errno = EFTYPE;
		close(fd);
	}
	if (!errno && file_size > (long)MAX_SIZE_FILE)
		errno = EFBIG;
	if (errno)
		return (False);
	return (True);
}
