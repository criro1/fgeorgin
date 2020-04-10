/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_is_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:42:50 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 15:41:41 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_if_line_0(char *ln)
{
	if (ln[1] == 'i' && ln[2] == 'v' && ln[3] == 'e' &&
		(ft_isspace(ln[4]) || ln[4] == DIRECT_CHAR || ln[4] == '-'))
		return (1);
	else if (ln[1] == 'd')
	{
		if (ln[2] == 'i' && (ft_isspace(ln[3]) ||
			ln[3] == DIRECT_CHAR || ln[3] == '-'))
			return (1);
		else if (ft_isspace(ln[2]) || ln[2] == DIRECT_CHAR || ln[2] == '-')
			return (1);
	}
	else if (ln[1] == 'l' && ln[2] == 'd')
	{
		if (ln[3] == 'i' && (ft_isspace(ln[4]) ||
			ln[4] == DIRECT_CHAR || ln[4] == '-'))
			return (1);
		else if (ft_isspace(ln[3]) || ln[3] == DIRECT_CHAR || ln[3] == '-')
			return (1);
	}
	else if (ln[1] == 'f')
		if (ln[2] == 'o' && ln[3] == 'r' && ln[4] == 'k' &&
			(ft_isspace(ln[5]) || ln[5] == DIRECT_CHAR || ln[5] == '-'))
			return (1);
	return (0);
}

int			begin_is_instruction_1(char *line)
{
	if (line[0] == 'a')
	{
		if (line[1] == 'd' && line[2] == 'd' &&
			(ft_isspace(line[3]) || line[3] == DIRECT_CHAR))
			return (1);
		else if (line[1] == 'n' && line[2] == 'd' &&
			(ft_isspace(line[3]) || line[3] == DIRECT_CHAR || line[3] == '-'))
			return (1);
		else if (line[1] == 'f' && line[2] == 'f' &&
			(ft_isspace(line[3]) || line[3] == DIRECT_CHAR))
			return (1);
	}
	else if (!ft_strncmp(line, "or", 2) &&
		(ft_isspace(line[2]) || line[2] == DIRECT_CHAR || line[2] == '-'))
		return (1);
	else if (!ft_strncmp(line, "xor", 3) &&
		(ft_isspace(line[3]) || line[3] == DIRECT_CHAR || line[3] == '-'))
		return (1);
	else if (!ft_strncmp(line, "zjmp", 4) &&
		(ft_isspace(line[4]) || line[4] == DIRECT_CHAR || line[4] == '-'))
		return (1);
	else if (!ft_strncmp(line, "fork", 4) &&
		(ft_isspace(line[4]) || line[4] == DIRECT_CHAR || line[4] == '-'))
		return (1);
	return (0);
}

int			begin_is_instruction(char *line)
{
	if (line[0] == 'l')
	{
		if (ft_if_line_0(line) == 1)
			return (1);
	}
	else if (line[0] == 's')
	{
		if (line[1] == 'u' && line[2] == 'b' &&
			(ft_isspace(line[3]) || line[3] == DIRECT_CHAR))
			return (1);
		else if (line[1] == 't')
		{
			if (line[2] == 'i' &&
				(ft_isspace(line[3]) || line[3] == DIRECT_CHAR))
				return (1);
			else if (ft_isspace(line[2]) || line[2] == DIRECT_CHAR)
				return (1);
		}
	}
	else
	{
		if (begin_is_instruction_1(line) == 1)
			return (1);
	}
	return (0);
}
