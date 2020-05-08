/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:32:10 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/23 10:57:59 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_players	*new_players(void)
{
	t_players	*o_new;

	o_new = (t_players *)ft_memalloc(sizeof(t_players));
	return (o_new);
}
