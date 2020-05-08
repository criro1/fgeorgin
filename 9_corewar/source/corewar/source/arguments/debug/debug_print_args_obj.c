/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debag_print_args_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:46:53 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/17 18:10:56 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_options(t_options_list *i_top_list)
{
	t_options_list	*iterator;
	int				indent;
	int				counter;

	if (i_top_list)
	{
		indent = 20;
		counter = 1;
		iterator = i_top_list;
		while (iterator)
		{
			print_line('_', 19, False);
			ft_printf(" %d ", counter++);
			print_line('_', 19, True);
			ft_printf("	%-*s = %d\n", indent, "id", iterator->id);
			ft_printf("	%-*s = %s\n", indent, "option_obj",
										iterator->option_obj ? "Yes" : "No");
			ft_printf("	%-*s = %s\n", indent, "name", iterator->name);
			print_line('-', 41, True);
			iterator = iterator->next;
		}
	}
	else
		ft_printf("NULL\n");
}

void		debug_print_args_obj(t_args_obj *i_args)
{
	ft_printf("<OPTIONS>\n");
	print_options(i_args->options);
	ft_printf("<PLAYERS>\n");
	debug_print_players(i_args->players, 20, 0);
}
