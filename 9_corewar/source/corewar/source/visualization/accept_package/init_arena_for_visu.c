/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena_for_visu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:53:33 by astamm            #+#    #+#             */
/*   Updated: 2020/03/15 18:02:12 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	init_arena_for_visu(t_package *package, t_visu *visu)
{
	int div;
	int mod;

	visu->arena = package->content;
	package->content = NULL;
	visu->size_arena = package->size_package;
	visu->sqrt_arena = BYTES_IN_STR;
	div = visu->size_arena / BYTES_IN_STR;
	mod = visu->size_arena % BYTES_IN_STR;
	visu->amount_string = mod == 0 ? div : div + 1;
	visu->bytes_in_last_str = mod == 0 ? BYTES_IN_STR : mod;
}
