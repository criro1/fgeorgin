/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:23:21 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 15:40:07 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			open_error_exit(void)
{
	perror("Can't open file");
	exit(EXIT_FAILURE);
}

static void			skip_spaces(char **line)
{
	while (ft_isspace(**line))
		++(*line);
}

static void			skip_comment(char **line)
{
	if (**line == COMMENT_CHAR || **line == COMMENT_CHAR_2)
		while (**line)
			++(*line);
}

static void			parse_line(t_token_list *token_list, char *line, int fd)
{
	char			*ptr;

	if ((ptr = ft_strstr(line, NAME_CMD_STRING)) && name_is_correct(ptr))
		get_name(ptr, token_list, line, fd);
	else if ((ptr = ft_strstr(line, COMMENT_CMD_STRING))
		&& comment_is_correct(ptr))
		get_comment(ptr, token_list, line, fd);
	else
		check_line_beginning(token_list, line);
}

void				assemble(char *filename)
{
	t_token_list	*token_list;
	int				fd;
	int				gnl_ret;
	char			*line;
	char			*ptr;

	fd = open(filename, O_RDONLY);
	if (read(fd, NULL, 0) || errno)
		open_error_exit();
	if (!(token_list = (t_token_list*)ft_memalloc(sizeof(t_token_list))))
		exit(1);
	while ((gnl_ret = get_next_line(fd, &line) > 0))
	{
		ptr = line;
		skip_spaces(&ptr);
		skip_comment(&ptr);
		parse_line(token_list, ptr, fd);
		ft_strdel(&line);
	}
	(gnl_ret == -1) ? ft_exit(token_list, "Read error. GNL\n") : 0;
	ft_strdel(&line);
	parser(&token_list);
	to_byte_code(token_list, filename);
	clean(token_list);
	close(fd);
}
