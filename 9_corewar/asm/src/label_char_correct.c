/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_char_correct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:46:15 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/13 17:16:03 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		label_char_correct(char label_char)
{
	int	i;

	i = -1;
	while (LABEL_CHARS[++i])
		if (label_char == LABEL_CHARS[i])
			return (1);
	return (0);
}
