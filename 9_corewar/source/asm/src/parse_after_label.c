/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_after_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:26:43 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 10:46:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				parse_after_label(char *line, t_token_list *token_list)
{
	t_token_node	*token;
	char			*ptr;

	token = NULL;
	ptr = line;
	if (begin_is_instruction(line))
	{
		while (*ptr && !ft_isspace(*ptr) && *ptr != DIRECT_CHAR)
			ptr++;
		create_token(&token, token_list);
		token->content = ft_strnct_fr(token->content, line, ptr - line);
		token->type = ft_strjoin_free(token->type, "instruction");
		parse_args(ptr, token_list);
	}
	else if (*ptr == COMMENT_CHAR || *ptr == COMMENT_CHAR_2)
		return ;
	else
		ft_exit(token_list, "Error: bad symbols after label\n");
	token_list->name += 0;
}
