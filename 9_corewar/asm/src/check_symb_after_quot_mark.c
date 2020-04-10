/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symb_after_quot_mark.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:31:29 by cwitting          #+#    #+#             */
/*   Updated: 2020/02/07 16:35:02 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		line_has_comments(char *line)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR ||
		*line == COMMENT_CHAR_2)
			return (1);
		++line;
	}
	return (0);
}

int				check_symb_after_quot_mark(char *line)
{
	char	*ptr;

	while (*line && *line != '"')
		++line;
	ptr = ++line;
	if (line_has_comments(ptr))
	{
		while (*ptr != COMMENT_CHAR && *ptr != COMMENT_CHAR_2)
		{
			if (!ft_isspace(*ptr))
				return (0);
			ptr++;
		}
	}
	else
		while (*ptr)
			if (!ft_isspace(*ptr++))
				return (0);
	return (1);
}
