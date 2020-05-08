/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:49:28 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 16:05:29 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	*new_corewar(t_args_obj *m_args)
{
	t_corewar	*o_new;
	t_boolean	error;

	error = False;
	if ((o_new = (t_corewar *)ft_memalloc(sizeof(t_corewar))))
	{
		o_new->options = pop_options(m_args);
		o_new->players = pop_players(m_args);
		*(unsigned int*)&g_options =
			(unsigned int)options_fetch_bits_flag(o_new->options);
		if (!init_players(o_new->players))
			error = True;
		if (!error && !(o_new->memory = new_memory(o_new->players)))
			error = True;
		if (!error && !(o_new->params = new_params(o_new->players)))
			error = True;
		if (!error && !(o_new->carriages = new_carriages(o_new->memory)))
			error = True;
		if (error)
			destroy_corewar(&o_new);
	}
	return (o_new);
}
