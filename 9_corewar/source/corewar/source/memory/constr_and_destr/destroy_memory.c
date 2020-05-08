/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:57:09 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 14:18:22 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_memory(t_memory **del_memory)
{
	if (del_memory && *del_memory)
	{
		ft_memdel((void **)&(*del_memory)->segments);
		ft_memdel((void **)&(*del_memory)->mem);
		ft_bzero(*del_memory, sizeof(t_memory));
		ft_memdel((void**)del_memory);
	}
}
