/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_set_reg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:51:24 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:20:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		carriage_set_reg(t_carriage *m_carriage, int i_reg, int i_data)
{
	int		index_reg;

	index_reg = i_reg - 1;
	if (index_reg > -1 && index_reg < REG_NUMBER)
		m_carriage->reg[index_reg] = i_data;
	else
		save_error_to_log("Carriage : Can't set data ", "Invalid reg");
}
