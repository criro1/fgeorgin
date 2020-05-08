/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init_carriage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:11:19 by astamm            #+#    #+#             */
/*   Updated: 2020/03/13 19:19:05 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_init_carriage(t_visu *visu)
{
	int index;

	index = 0;
	while (index < visu->struct_carriages.amount)
	{
		visu_new_carriage(visu, visu->struct_carriages.carriages[index]);
		index++;
	}
}
