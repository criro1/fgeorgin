/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:32:19 by cwitting          #+#    #+#             */
/*   Updated: 2020/02/07 16:34:31 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_size(char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (content[i])
		++i;
	if (i > size)
		return (0);
	return (1);
}
