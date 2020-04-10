/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:29:47 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/01 20:46:56 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar(int argc, char **argv)
{
	t_args_obj	*args;
	t_corewar	*corewar;
	int			*obj_d;

	if (!(args = new_args_obj(argc, argv)))
		ft_exit(E_NO_MEM);
	//debag
	else
	{
		ft_printf("Created args_obj %s\n", args->players->player[0]->file->path);
		debug_print_args_obj(args);
		obj_d = get_option_obj(args, "d");
		ft_printf("\n\n d options  = %d\n\n", (obj_d ? *obj_d : -1));
		debug_print_args_obj(args);
		ft_memdel((void**)&obj_d);

		corewar = new_corewar(args);
		destroy_args_obj(&args);
		corewar_run(corewar);
		
		ft_printf(">>>>> %s\n", corewar->params->pl_live->name);
		ft_printf(">>>>> %d\n", corewar->params->pl_live->order);
		ft_printf(">>>>> %ld\n", corewar->params->cycle);
		ft_printf(">>>>> %d\n", corewar->params->num_oper_live);
		ft_printf(">>>>> %d\n", corewar->params->cycles_to_die);
		ft_printf(">>>>> %d\n", corewar->params->number_checks);
		ft_printf("\n\n>>>>> %d\n", corewar->carriages->carriages->carriage->reg[0]);
		ft_printf(">>>>> %d\n", corewar->carriages->carriages->carriage->address);

		debug_print_players(corewar->players, 20, 10);

	}
}
