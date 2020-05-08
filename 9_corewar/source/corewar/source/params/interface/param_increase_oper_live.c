/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_increase_oper_live.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:13:14 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/07 20:19:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	param_increase_oper_live(t_params *m_params)
{
	++m_params->num_oper_live;
}
