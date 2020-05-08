/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_error_to_log.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:56:27 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:38:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <time.h>

static t_boolean	is_exist_file(char *i_path)
{
	int		fd;
	int		save_errno;

	save_errno = (int)errno;
	if ((fd = open(i_path, O_RDONLY)) < 0)
	{
		errno = save_errno;
		return (False);
	}
	close(fd);
	errno = save_errno;
	return (True);
}

static int			set_flags_open(char *i_file_path)
{
	return (is_exist_file(i_file_path) ? O_WRONLY | O_APPEND
										: O_WRONLY | O_TRUNC | O_CREAT);
}

void				save_error_to_log(char *i_massage1, char *i_massage2)
{
	char	*error_name;
	int		fd;

	if ((fd = open(LOG_FILE_NAME, set_flags_open(LOG_FILE_NAME), 511)) < 0)
		perror("There is no way to write to the log file");
	else
	{
		i_massage1 ? ft_dprintf(fd, "%s :", i_massage1) : 0;
		i_massage2 ? ft_dprintf(fd, "%s :", i_massage2) : 0;
		error_name = strerror((int)errno);
		errno ? ft_dprintf(fd, "%s", error_name) : 0;
		ft_dprintf(fd, "\n");
		close(fd);
	}
	errno = 0;
}
