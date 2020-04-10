/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 08:22:13 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 15:46:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_ptr_register_char(char **right, char **ptr,
					t_token_list **token_list)
{
	(*right) = (*ptr);
	while ((**right) && (**right) != SEPARATOR_CHAR && !ft_isspace((**right))
		&& **right != COMMENT_CHAR && **right != COMMENT_CHAR_2)
		++(*right);
	create_arg((*token_list), "register", (*ptr), (*right));
	if (!(check_valid_token((*token_list)->end, 0)))
	{
		ft_printf("%s - %s\n", (*token_list)->end->type,
			(*token_list)->end->content);
		ft_exit((*token_list), "Invalid register\n");
	}
}

void			ft_end_of_while_parse_args(t_token_list **token_list,
						int *arg_amount, char **right, int *arg_max)
{
	if ((*arg_amount) == (*arg_max))
	{
		while ((**right) && ft_isspace((**right)))
			++(*right);
		if ((**right) && (**right) != ';' && (**right) != '#')
			ft_exit((*token_list), "Error: parse after arguments\n");
		while ((**right))
			(*right)++;
	}
	if (ft_isspace((**right)))
		while (ft_isspace((**right)))
			++(*right);
	if ((**right) && (**right) == SEPARATOR_CHAR)
		(*right)++;
	else if ((**right))
		ft_exit((*token_list), "Missing separator\n");
}

void			ft_if_ptr_direct_char_1(t_token_list **token_list,
					char **right, char *ptr)
{
	if (ft_isdigit(*(ptr + 1)) || *(ptr + 1) == '-')
	{
		(*right) = ptr;
		while ((**right) && (**right) != SEPARATOR_CHAR &&
			!ft_isspace((**right)) && **right != COMMENT_CHAR
										&& **right != COMMENT_CHAR_2)
			++(*right);
		create_arg((*token_list), "direct", ptr, (*right));
		if (!(check_valid_token((*token_list)->end, 2)))
		{
			ft_printf("%s - %s\n", (*token_list)->end->type,
				(*token_list)->end->content);
			ft_exit((*token_list), "Invalid direct\n");
		}
	}
}

void			ft_if_ptr_direct_char(t_token_list **token_list,
					char **right, char *ptr)
{
	if (*(ptr + 1) == LABEL_CHAR)
	{
		(*right) = ptr;
		while ((**right) && (**right) != SEPARATOR_CHAR &&
			!ft_isspace((**right)) && **right != COMMENT_CHAR
									&& **right != COMMENT_CHAR_2)
			++(*right);
		create_arg((*token_list), "dir_label", ptr + 2, (*right));
		if (!(check_valid_token((*token_list)->end, 1)))
		{
			ft_printf("%s - %s\n", (*token_list)->end->type,
				(*token_list)->end->content);
			ft_exit((*token_list), "Invalid dir_label\n");
		}
	}
	else
		ft_if_ptr_direct_char_1(token_list, right, ptr);
}

void			ft_if_ptr_label_char(t_token_list **token_list,
					char **right, char *ptr)
{
	(*right) = ptr;
	while ((**right) && (**right) != SEPARATOR_CHAR && !ft_isspace((**right))
		&& **right != COMMENT_CHAR && **right != COMMENT_CHAR_2)
		++(*right);
	if (*ptr == LABEL_CHAR)
	{
		create_arg((*token_list), "indir_label", ptr + 1, (*right));
		if (!(check_valid_token((*token_list)->end, 3)))
		{
			ft_printf("%s - %s\n", (*token_list)->end->type,
				(*token_list)->end->content);
			ft_exit((*token_list), "Invalid indir_label\n");
		}
	}
	else
	{
		create_arg((*token_list), "indirect", ptr, (*right));
		if (!(check_valid_token((*token_list)->end, 4)))
		{
			ft_printf("%s - %s\n", (*token_list)->end->type,
				(*token_list)->end->content);
			ft_exit((*token_list), "Invalid indirect\n");
		}
	}
}
