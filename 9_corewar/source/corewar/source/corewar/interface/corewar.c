/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:29:47 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 18:09:17 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar(int argc, char **argv)
{
	t_args_obj	*args;
	t_corewar	*corewar;

	if (!(args = new_args_obj(argc, argv)))
		ft_exit(E_NO_MEM);
	corewar = new_corewar(args);
	destroy_args_obj(&args);
	if (!corewar)
		ft_exit(NULL);
	corewar_run(corewar);
	destroy_corewar(&corewar);
}
