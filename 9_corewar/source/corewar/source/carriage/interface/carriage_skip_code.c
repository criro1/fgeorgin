/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_skip_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:08:43 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 19:42:16 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	carriage_skip_code(t_carriage *m_carriage, t_code *i_code)
{
	if (i_code->size > -1)
		m_carriage->address = memory_shift(m_carriage->address, i_code->size);
	else
		save_error_to_log("Carrige ", "Invalide code size, can't skip code");
}
