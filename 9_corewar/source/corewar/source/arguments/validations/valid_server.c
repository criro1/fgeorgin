/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:46:54 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/13 22:03:51 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_boolean	is_extra_options_server(char *i_option)
{
	if (i_option && (!ft_strcmp("-port", i_option)
				|| !ft_strcmp("-pass", i_option)
					|| !ft_strcmp("-players", i_option)))
		return (True);
	return (False);
}

static int			fetch_number(t_valid_args *i_valid)
{
	int o_number;

	o_number = 0;
	if (is_number(i_valid->argv[i_valid->current_arg + 1]))
	{
		o_number = ft_atoi(i_valid->argv[i_valid->current_arg + 1]);
		if (is_overflow(o_number, i_valid->argv[i_valid->current_arg + 1]))
			errno = EOVERFLOW;
	}
	else
		errno = EINVAL;
	return (o_number);
}

static void			valid_extra_opt_server(t_valid_args *i_valid)
{
	int		number;

	if (!ft_strcmp("-port", i_valid->argv[i_valid->current_arg]))
	{
		if ((number = fetch_number(i_valid)) >= 0 && !errno)
			if (number < 1024 || number >= 49151)
				errno = EINVAL;
	}
	else if (!ft_strcmp("-pass", i_valid->argv[i_valid->current_arg]))
	{
		if (ft_strlen(i_valid->argv[i_valid->current_arg + 1]) > MAX_LEN_PASS)
			errno = EINVAL;
	}
	else if (!ft_strcmp("-players", i_valid->argv[i_valid->current_arg]))
	{
		number = fetch_number(i_valid);
		if (!errno)
			if (number < MIN_PLAYERS || number > MAX_PLAYERS)
				errno = EINVAL;
	}
}

void				valid_server(t_valid_args *m_valid)
{
	t_boolean	have_extra_opt;

	if (m_valid->current_arg + 1 <= m_valid->argc)
	{
		have_extra_opt = False;
		++m_valid->current_arg;
		while (is_extra_options_server(m_valid->argv[m_valid->current_arg])
					&& !errno)
		{
			if (m_valid->current_arg + 1 >= m_valid->argc)
				errno = EINVAL;
			else
			{
				valid_extra_opt_server(m_valid);
				m_valid->current_arg += 2;
			}
			if (!have_extra_opt)
				have_extra_opt = True;
		}
		--m_valid->current_arg;
	}
}
