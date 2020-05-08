/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_set_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:48:14 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:22:58 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	carriage_set_id(t_carriage *i_carriage, int i_id)
{
	if (i_id < 0)
	{
		save_error_to_log("Carriage ", "Invalid id ");
		return (False);
	}
	if (i_carriage->id < 0)
	{
		i_carriage->id = i_id;
		return (True);
	}
	else
		save_error_to_log("Carriage ", " Id is already taken ");
	return (False);
}
