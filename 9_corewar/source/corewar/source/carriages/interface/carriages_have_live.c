/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_have_live.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:30:52 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/15 23:00:37 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	carriages_have_live(t_carriages *i_carriages)
{
	if (i_carriages->amount > 0)
		return (True);
	return (False);
}
