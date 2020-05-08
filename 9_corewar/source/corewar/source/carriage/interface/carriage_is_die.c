/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_is_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:26:49 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/15 22:51:50 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	carriage_is_die(t_carriage *i_carr, int i_curr_cycl, int i_die_cycl)
{
	if (i_die_cycl <= 0 || i_carr->cycle_live <= (i_curr_cycl - i_die_cycl))
		return (True);
	return (False);
}
