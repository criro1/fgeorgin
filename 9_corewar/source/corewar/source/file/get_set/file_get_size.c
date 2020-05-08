/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:17:02 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:33:28 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static long int	measure_file(char *i_path)
{
	int			fd;
	long		o_size;

	o_size = 0;
	if ((fd = open(i_path, O_RDONLY)) >= 0)
		o_size = lseek(fd, 0, SEEK_END);
	if (errno)
		save_error_to_log("File: can't get size", i_path);
	return (o_size);
}

long int		file_get_size(t_file *m_file, char *i_units)
{
	long int	o_size;

	o_size = 0;
	if (!m_file->size)
		m_file->size = measure_file(m_file->path);
	if (!i_units || !ft_strcmp(i_units, "byte"))
		o_size = m_file->size;
	return (o_size);
}
