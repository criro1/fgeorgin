/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_get_players_last_live.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:58:54 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/24 17:09:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*params_get_players_last_live(t_params *i_params)
{
	return (i_params->pl_live);
}
