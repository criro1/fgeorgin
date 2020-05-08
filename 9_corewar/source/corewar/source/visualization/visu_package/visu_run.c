/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:24:56 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 16:25:26 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visu_run(int fd)
{
	t_visu		visu;
	t_package	package;
	int			prev_speed;

	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		return ;
	}
	visu = visu_init(fd);
	print_arena(&visu);
	print_init_player(&visu);
	print_init_carriage(&visu);
	visu.keyboard->pause = True;
	prev_speed = DEFAULT_SPEED_VISU;
	visu.keyboard->microseconds = 20000;
	while (visu.exit == False)
	{
		package = get_package(fd);
		key_processing_visu(&visu, &package, &prev_speed);
		rendering(&visu, &package);
		destroy_package_visu(&package);
	}
	destroy_visu(&visu);
}
