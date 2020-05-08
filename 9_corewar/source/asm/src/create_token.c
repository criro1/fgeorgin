/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:28:52 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/03 17:34:50 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			create_token(t_token_node **token, t_token_list *token_list)
{
	if (!(*token = (t_token_node*)ft_memalloc(sizeof(t_token_node))))
		exit(1);
	(*token)->content = ft_strnew(0);
	(*token)->type = ft_strnew(0);
	if (!token_list->head)
	{
		token_list->head = *token;
		token_list->end = *token;
		(*token)->next = NULL;
	}
	else if (token_list->head && token_list->head == token_list->end)
	{
		token_list->head->next = *token;
		token_list->end = *token;
		(*token)->next = NULL;
	}
	else
	{
		token_list->end->next = *token;
		token_list->end = *token;
	}
}
