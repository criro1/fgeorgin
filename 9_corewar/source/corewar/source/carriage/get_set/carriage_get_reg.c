/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_get_reg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:55:16 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/07 18:01:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			carriage_get_reg(t_carriage *m_carrige, int i_reg)
{
	int		index_reg;

	index_reg = i_reg - 1;
	if (index_reg > -1 && index_reg < REG_NUMBER)
		return (m_carrige->reg[index_reg]);
	else
		save_error_to_log("Carriage: Can't get reg", "Invalid reg num");
	return (0);
}
