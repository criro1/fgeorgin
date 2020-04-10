/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:49:28 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/01 19:15:34 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	*new_corewar(t_args_obj *m_args)
{
	t_boolean	init_pls;
	t_corewar	*o_new;
	
	init_pls = False;
	if ((o_new = (t_corewar *)ft_memalloc(sizeof(t_corewar))))
	{
		o_new->options = pop_options(m_args);
		o_new->players = pop_players(m_args);
		//debag
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ */
		init_pls = init_players(o_new->players);
		ft_printf("init player return = %s\n", init_pls ? "True" : "False");
		if (!init_pls)
			return (NULL);
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ */
		if (!(o_new->memory = new_memory(o_new->players)))
			return (NULL);
		if (!(o_new->params = new_params(o_new->players)))
			return (NULL);
		if (!(o_new->carriages = new_carriages(o_new->memory)))
			return (NULL);
	}
	return (o_new);
}
