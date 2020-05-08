/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_need_set_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:07:09 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/13 12:39:09 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	carriage_need_set_code(t_carriage *i_carriage)
{
	if (i_carriage->cycle_to_exec > 0)
		return (False);
	return (True);
}
