/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_options_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:08:08 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:21:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	is_options_player(char *i_options)
{
	if (*i_options == 'n')
		return (True);
	return (False);
}
