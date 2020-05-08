/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:17:08 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/31 21:52:43 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_params	*new_params(t_players *i_pls)
{
	t_params	*o_new;
	t_player	*pl_live;

	if ((o_new = ft_memalloc(sizeof(t_params))))
	{
		pl_live = players_get_player(i_pls, players_get_amount(i_pls));
		o_new->pl_live = pl_live;
		o_new->cycles_to_die = CYCLE_TO_DIE;
	}
	else
		save_error_to_log("Params ", NULL);
	return (o_new);
}
