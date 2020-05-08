/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:57:19 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/23 18:59:42 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	valid_dump(t_valid_args *m_valid)
{
	int		number;

	if (m_valid->current_arg + 1 >= m_valid->argc)
		errno = EINVAL;
	else
	{
		++m_valid->current_arg;
		if (is_number(m_valid->argv[m_valid->current_arg]))
		{
			number = ft_atoi(m_valid->argv[m_valid->current_arg]);
			if (is_overflow(number, m_valid->argv[m_valid->current_arg]))
				errno = EOVERFLOW;
			else if (number < 0)
				errno = EINVAL;
		}
		else
		{
			--m_valid->current_arg;
			errno = EINVAL;
		}
	}
}
