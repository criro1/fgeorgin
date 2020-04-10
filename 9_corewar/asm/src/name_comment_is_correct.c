/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment_is_correct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:28:58 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 10:35:19 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				comment_is_correct(char *ptr)
{
	char		buf[COMMENT_LENGTH + 1];
	unsigned	i;

	i = 0;
	while (!ft_isspace(*ptr) && *ptr != '"')
		buf[i++] = *ptr++;
	buf[i] = '\0';
	if (!ft_strcmp(buf, COMMENT_CMD_STRING))
		return (1);
	return (0);
}

int				name_is_correct(char *ptr)
{
	char		buf[PROG_NAME_LENGTH + 1];
	unsigned	i;

	i = 0;
	while (!ft_isspace(*ptr) && *ptr != '"')
		buf[i++] = *ptr++;
	buf[i] = '\0';
	if (!ft_strcmp(buf, NAME_CMD_STRING))
		return (1);
	return (0);
}
