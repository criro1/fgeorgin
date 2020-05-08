/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:54:01 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/14 13:25:58 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	params_reset(t_params *m_params)
{
	if (m_params->num_oper_live >= NBR_LIVE ||
			m_params->number_checks >= MAX_CHECKS)
		m_params->number_checks = 0;
	m_params->num_oper_live = 0;
}
