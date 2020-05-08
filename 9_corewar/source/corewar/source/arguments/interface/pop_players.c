/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:15:03 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/25 20:17:38 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_players		*pop_players(t_args_obj *m_args)
{
	t_players	*o_players;

	o_players = m_args->players;
	m_args->players = NULL;
	return (o_players);
}
