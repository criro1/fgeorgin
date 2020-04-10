/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:04:54 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/23 11:10:29 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_options(t_options_list **m_top)
{
	if (*m_top)
	{
		destroy_options(&(*m_top)->next);
		destroy_options_list(m_top);
	}
}
