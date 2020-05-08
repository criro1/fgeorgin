/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_args_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:24:47 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:02:37 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_args_obj	*new_args_obj(int i_argc, char **i_argv)
{
	t_args_obj	*o_new;
	int			current_arg;

	validation_args(i_argc, i_argv);
	if (!(o_new = (t_args_obj *)ft_memalloc(sizeof(t_args_obj)))
				|| !(o_new->players = new_players()))
		ft_exit(E_NO_MEM);
	current_arg = 1;
	while (current_arg < i_argc)
	{
		if (is_options(i_argv[current_arg]))
			add_new_options_to_arg_obj(o_new, &current_arg, i_argv);
		else
			add_file_new_player_to_arg_obj(o_new, i_argv[current_arg]);
		++current_arg;
	}
	return (o_new);
}
