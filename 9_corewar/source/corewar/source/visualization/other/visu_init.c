/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:37:56 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 15:52:48 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_struct_carriages(t_visu_carriagess *struct_carriages)
{
	struct_carriages->amount = 0;
	struct_carriages->memory_allocated = sizeof(t_visu_carriage*)
														* AND_MEM_CARRIAGES;
	struct_carriages->carriages =
						ft_memalloc(struct_carriages->memory_allocated);
	struct_carriages->amount_maloc_car = AND_MEM_CARRIAGES;
}

static void	init_keyboard(t_visu *visu)
{
	visu->keyboard = ft_memalloc(sizeof(t_visu_keyboard));
	visu->keyboard->speed = 50;
	constructor_windows(visu);
	visu->keyboard->w_info = visu->w_info;
	pthread_create(&visu->thread, NULL, keyboard_control, visu->keyboard);
}

t_visu		visu_init(int fd)
{
	t_visu		visu;
	t_package	package;

	ft_bzero(&visu, sizeof(t_visu));
	init_struct_carriages(&visu.struct_carriages);
	init_keyboard(&visu);
	init_color_pairs();
	package.code_package = 0;
	while (package.code_package != CODE_PACKAGE_END_INIT)
	{
		package = get_package(fd);
		processing_package_for_init(&package, &visu);
	}
	set_color_players(&visu.gamers);
	set_color_carriages(&visu);
	set_start_end_code_players(&visu.gamers, &visu.struct_carriages);
	return (visu);
}
