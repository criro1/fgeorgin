/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:52:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:06:03 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_number(t_valid_args *m_valid)
{
	int		number;

	if (is_number(m_valid->argv[m_valid->current_arg]))
	{
		number = ft_atoi(m_valid->argv[m_valid->current_arg]);
		if (is_overflow(number, m_valid->argv[m_valid->current_arg]))
			errno = EOVERFLOW;
		else if (number < MIN_PLAYERS || number > MAX_PLAYERS)
			errno = EINVAL;
		else if ((1 << (number - 1)) & m_valid->order_files)
			errno = EINVAL;
		else
			m_valid->order_files |= (1 << (number - 1));
	}
	else
		errno = EINVAL;
}

static void	check_file(t_valid_args *m_valid)
{
	if (!is_suitable_file(m_valid->argv[m_valid->current_arg]))
		if (!errno)
			errno = 79;
}

void		valid_n(t_valid_args *m_valid)
{
	if (m_valid->current_arg + 2 >= m_valid->argc)
		errno = EINVAL;
	else
	{
		++m_valid->current_arg;
		check_number(m_valid);
		if (!errno)
		{
			++m_valid->current_arg;
			check_file(m_valid);
			if (!errno)
				++m_valid->amount_files;
		}
	}
}
