/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:38:35 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 17:28:20 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	rendering(t_visu *visu, t_package *package)
{
	if (package->code_package == CODE_PACKAGE_WRITE_IN_MEM)
		visu_write_in_mem(visu, package);
	else if (package->code_package == CODE_PACKAGE_END_GAME)
		visu->exit = True;
	else if (package->code_package == CODE_PACKAGE_NEW_CARRIAGE)
		accept_package_new_carriage(package, &visu->struct_carriages, visu);
	else if (package->code_package == CODE_PACKAGE_CHANGE_CARRIAGE_ADDRESS)
		accept_package_change_carriage_addres(package, &visu->struct_carriages,
																		visu);
	else if (package->code_package == CODE_PACKAGE_CHANGE_CYCLES)
		visu_increase_cycles(package, visu);
	else if (package->code_package == CODE_PACKAGE_CHANGE_CTD)
		visu_decrease_ctd(package, visu);
	else if (package->code_package == CODE_PACKAGE_DEATH_CARRIAGE)
		visu_death_carriage(package, visu, &visu->struct_carriages);
	else if (package->code_package == CODE_PACKAGE_PLAYER_SAY_LIVE)
		visu_player_say_live(package, visu);
	else if (package->code_package == CODE_PACKAGE_WINNING_PLAYER)
		visu_winning_player(package, visu);
}
