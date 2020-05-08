/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 23:41:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:34:26 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	file_open(t_file *m_file, int i_oflag, ...)
{
	va_list	ap;
	mode_t	mode;

	if (i_oflag & O_CREAT)
	{
		va_start(ap, i_oflag);
		mode = va_arg(ap, int);
		if ((m_file->fd = open(m_file->path, i_oflag, mode)) < 0)
			save_error_to_log("File: can't open", m_file->path);
		va_end(ap);
	}
	else if ((m_file->fd = open(m_file->path, i_oflag)) < 0)
		save_error_to_log("File: can't open", m_file->path);
	if (m_file->fd < 0)
		return (False);
	m_file->open = True;
	return (True);
}
