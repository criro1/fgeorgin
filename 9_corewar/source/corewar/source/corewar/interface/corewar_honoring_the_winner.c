/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_honoring_the_winner.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:53:59 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/24 17:11:15 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar_honoring_the_winner(t_corewar *i_corewar)
{
	player_say_won(params_get_players_last_live(i_corewar->params));
}
