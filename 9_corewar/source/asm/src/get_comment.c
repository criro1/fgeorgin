/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:30:31 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 10:24:27 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void				ft_check_if_quot_mark(t_token_list *token_list,
							char *ptr)
{
	int	i;

	i = 0;
	if (ptr[i] == '"')
	{
		i++;
		while (ptr[i])
		{
			if (ptr[i] == COMMENT_CHAR || ptr[i] == COMMENT_CHAR_2)
				break ;
			if (!(ft_isspace(ptr[i])))
				ft_exit(token_list,
					"Error: bad symbols after champion's comment\n");
			i++;
		}
	}
}

static void				ft_if_check_symb_after_quot(t_token_list *token_list,
							char *line)
{
	if (!check_symb_after_quot_mark(line))
	{
		ft_memdel((void**)&line);
		ft_exit(token_list,
			"Error: bad symbols after champion's comment\n");
	}
}

static void				if_ptr_equal_quot_mark(t_token_list *token_list,
							t_token_node **token, int fd)
{
	char				*line;

	while (get_next_line(fd, &line) > 0)
	{
		(*token)->content = ft_strjoin_free((*token)->content, "\n");
		if (!ft_strchr(line, '"'))
			(*token)->content = ft_strjoin_free((*token)->content, line);
		else
		{
			ft_if_check_symb_after_quot(token_list, line);
			(*token)->content = ft_strnjoin_free((*token)->content, line);
		}
		if (ft_strchr(line, '"'))
		{
			ft_memdel((void**)&line);
			break ;
		}
		ft_memdel((void**)&line);
	}
}

void					get_comment(char *ptr, t_token_list *token_list,
							char *line, int fd)
{
	char			*ptr_save;
	t_token_node	*token;

	if (token_list->comment == 1)
		ft_exit(token_list, "Error: multiple .comment\n");
	if (!(check_for_incorr_symb_before(line, ptr)) ||
			!(check_for_incorr_symb_after_dot_name(line, ptr)))
		ft_exit(token_list, "Error: bad symbols before / after .comment\n");
	create_token(&token, token_list);
	while (!ft_isspace(*ptr) && *ptr != '"')
		ptr++;
	while (*ptr != '"')
		if (!(ft_isspace(*ptr++)))
			ft_exit(token_list, "Error\n");
	ptr_save = ptr++;
	while (*ptr && *ptr != '"')
		ptr++;
	ft_check_if_quot_mark(token_list, ptr);
	token->content = ft_strnct_fr(token->content, ptr_save, ptr - ptr_save + 1);
	if (*ptr != '"')
		if_ptr_equal_quot_mark(token_list, &token, fd);
	if (!check_size(token->content, COMMENT_LENGTH + 2))
		ft_exit(token_list, "Error: incorrect comment size\n");
	token_list->comment = 1;
	token->type = ft_strjoin_free(token->type, "comment");
}
