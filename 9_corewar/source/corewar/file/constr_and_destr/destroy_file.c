/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:06:55 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/23 10:13:43 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_file(t_file **m_file)
{
	if (m_file && *m_file)
	{
		ft_memdel((void **)&(*m_file)->path);
		ft_memdel((void **)&(*m_file)->entry);
		ft_memdel((void**)m_file);
	}
}
