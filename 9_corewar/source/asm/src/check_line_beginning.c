/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_beginning.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:01:38 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 10:46:02 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			add_label_to_lst(char *line,
					t_token_list *tkn_lst, t_labels **label)
{
	char		*ptr;
	t_labels	*tmp;
	t_labels	*tmp_prev;

	tmp = tkn_lst->labels_head;
	tmp_prev = tkn_lst->labels_head;
	if (!(*label = (t_labels*)ft_memalloc(sizeof(t_labels))))
		exit(EXIT_FAILURE);
	(*label)->name = ft_strnew(0);
	ptr = line;
	while (*ptr && *ptr != LABEL_CHAR)
		++ptr;
	(*label)->name = ft_strnct_fr((*label)->name, line, ptr - line);
	if (!(tmp))
		tkn_lst->labels_head = *label;
	else
	{
		while (tmp)
		{
			tmp_prev = tmp;
			tmp = tmp->next;
		}
		tmp_prev->next = *label;
	}
	(*label)->bc = tkn_lst->bc;
}

static void			case_1_local(char *line, char *ptr,
						t_token_list *token_list)
{
	t_token_node	*token;
	t_labels		*label;

	token = NULL;
	add_label_to_lst(line, token_list, &label);
	create_token(&token, token_list);
	while (*ptr && *ptr != LABEL_CHAR)
		++ptr;
	token->content = ft_strnct_fr(token->content, line, ptr - line);
	token->type = ft_strjoin_free(token->type, "label");
	++ptr;
	if (*ptr && ft_isspace(*ptr))
		while (ft_isspace(*ptr))
			++ptr;
	if (*ptr)
		parse_after_label(ptr, token_list);
}

static void			case_2_local(char *line, char *ptr,
						t_token_list *token_list)
{
	t_token_node	*token;

	token = NULL;
	while (*ptr && !ft_isspace(*ptr) && *ptr != DIRECT_CHAR && *ptr != '-')
		ptr++;
	create_token(&token, token_list);
	token->content = ft_strnct_fr(token->content, line, ptr - line);
	token->type = ft_strjoin_free(token->type, "instruction");
	if (*ptr && ft_isspace(*ptr))
		while (ft_isspace(*ptr))
			++ptr;
	parse_args(ptr, token_list);
}

static int			beginning_is_label(char *line)
{
	if (*line)
	{
		while (*line && *line != LABEL_CHAR)
		{
			if (label_char_correct(*line))
				++line;
			else
				return (0);
		}
		if (*line == LABEL_CHAR)
			return (1);
	}
	return (0);
}

/*
**	check the beginning of the string:
**	valid: label or instruction
**	invalid: everything else
**	comments and empty lines are skipped before
*/

void				check_line_beginning(t_token_list *token_list, char *line)
{
	char			*ptr;

	ptr = line;
	if (*ptr && (!token_list->name || !token_list->comment))
		ft_exit(token_list, "No name or comment\n");
	if (beginning_is_label(line))
		case_1_local(line, ptr, token_list);
	else if (begin_is_instruction(line))
		case_2_local(line, ptr, token_list);
	else if (*line)
		ft_exit(token_list, "Error: bad symbols in line\n");
}
