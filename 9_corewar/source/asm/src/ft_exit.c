/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:42:00 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 15:42:28 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_exit(t_token_list *token_list, char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	clean(token_list);
	exit(EXIT_FAILURE);
}
