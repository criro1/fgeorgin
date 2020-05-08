/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_corewar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:50:38 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/13 22:04:28 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_corewar(t_corewar **del_corewar)
{
	if (del_corewar && *del_corewar)
	{
		destroy_players(&((*del_corewar)->players));
		destroy_options(&((*del_corewar)->options));
		destroy_memory(&((*del_corewar)->memory));
		destroy_params(&((*del_corewar)->params));
		destroy_carriages(&((*del_corewar)->carriages));
		ft_memdel((void**)del_corewar);
	}
}
