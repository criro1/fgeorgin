/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_options_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:08:08 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/11 13:27:07 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//Need refactoring
//add normal define and do the same as in validating validation arguments
t_boolean	is_options_player(char *i_options)
{
	if (*i_options == 'n')
		return (True);
	return (False);
}
