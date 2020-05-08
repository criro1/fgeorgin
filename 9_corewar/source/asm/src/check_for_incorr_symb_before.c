/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_incorr_symb_before.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:42:05 by cwitting          #+#    #+#             */
/*   Updated: 2020/02/07 16:43:28 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_for_incorr_symb_before(char *start, char *end)
{
	while (start != end)
	{
		if (!ft_isspace(*start))
			return (0);
		start++;
	}
	return (1);
}
