/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packages_init_corewar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:46:10 by astamm            #+#    #+#             */
/*   Updated: 2020/03/13 18:58:48 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	packages_init_corewar(t_corewar *corewar)
{
	package_init_players(corewar->players, corewar->fd);
	send_package_init_carriages(corewar->carriages, corewar->fd);
	package_init_memory(corewar->memory->mem, corewar->memory->size,
																corewar->fd);
	package_end_init(corewar->fd);
}
