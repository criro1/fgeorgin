/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 08:13:58 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 08:24:42 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			create_arg(t_token_list *token_list,
									char *arg_type, char *ptr, char *right)
{
	t_token_node	*token;

	create_token(&token, token_list);
	token->content = ft_strnct_fr(token->content, ptr, right - ptr);
	token->type = ft_strjoin_free(token->type, arg_type);
}
