/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_incorr_symb_after.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:21:51 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/13 22:58:02 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_for_incorr_symb_after_dot_name(char *start, char *end)
{
	end += 0;
	while (!ft_isspace(*start) && *start != '"')
		++start;
	while (*start && *start != '"')
	{
		if (!ft_isspace(*start))
			return (0);
		++start;
	}
	return (1);
}
