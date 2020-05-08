/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:04:26 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:41:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	memory_put_code_players(t_memory *m_mem, t_players *i_players)
{
	int		current_player;
	int		amount_playres;
	int		delta_address;
	int		address;

	if ((amount_playres = players_get_amount(i_players)) > 0)
	{
		address = 0;
		current_player = 1;
		delta_address = m_mem->size / amount_playres;
		while (current_player <= amount_playres)
		{
			if (address < (int)m_mem->size)
				players_memcpy(i_players, current_player, m_mem->mem + address);
			else
				save_error_to_log("Memory ", "Segment fult ");
			m_mem->segments[current_player - 1] = address;
			address += delta_address;
			++current_player;
		}
		m_mem->amount_segments = amount_playres;
	}
}

t_memory	*new_memory(t_players *i_pls)
{
	t_memory	*o_new;

	if (!i_pls || !(o_new = (t_memory *)ft_memalloc(sizeof(t_memory))))
		return (NULL);
	if (!(o_new->segments = ft_memalloc(sizeof(int) *
												players_get_amount(i_pls) + 1)))
	{
		ft_memdel((void**)&o_new);
		return (NULL);
	}
	if (!(o_new->mem = (unsigned char*)ft_memalloc(MEM_SIZE)))
	{
		ft_memdel((void**)&o_new->segments);
		ft_memdel((void**)&o_new);
		return (NULL);
	}
	o_new->size = MEM_SIZE;
	memory_put_code_players(o_new, i_pls);
	return (o_new);
}
