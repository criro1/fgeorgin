/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_obj_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:37:02 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/16 11:52:57 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*new_obj_dump(int *m_index_arg, char **i_argv)
{
	int	*new;

	++(*m_index_arg);
	if ((new = (int*)ft_memalloc(sizeof(int))))
		*new = ft_atoi(i_argv[*m_index_arg]);
	return ((void*)new);
}
