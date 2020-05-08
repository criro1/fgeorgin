/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_package_for_init.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:21:34 by astamm            #+#    #+#             */
/*   Updated: 2020/03/15 17:54:41 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	processing_package_for_init(t_package *package, t_visu *visu)
{
	if (package->code_package == CODE_PACKAGE_PLAYER)
		init_players_for_visu(package, visu);
	else if (package->code_package == CODE_PACKAGE_NEW_CARRIAGE)
		init_carriage_for_visu(package, &visu->struct_carriages,
															visu->w_dashboard);
	else if (package->code_package == CODE_PACKAGE_MEMORY)
		init_arena_for_visu(package, visu);
}
