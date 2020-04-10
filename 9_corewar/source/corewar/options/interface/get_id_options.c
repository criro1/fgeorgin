/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:05:45 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/09 14:05:50 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			check_only_first_symbol(char *i_what, char *i_where)
{
	if (*i_what == *i_where)
		return (0);
	return (1);
}

static t_boolean	find_options(int *m_caunter, char *i_options,
								char **i_where, int check_func(char *, char *))
{
	int	current_options;

	current_options = 0;
	while (*i_where[current_options])
	{
		if (!check_func(i_options, i_where[current_options]))
			return (True);
		++(*m_caunter);
		++current_options;
	}
	return (False);
}

int					get_id_options(char *i_options)
{
	int	(*check_func)(char *, char *);
	int	o_id;

	if (*(i_options + 1))
		check_func = (int (*)(char *, char *))ft_strcmp;
	else
		check_func = check_only_first_symbol;
	o_id = 0;
	if (find_options(&o_id, i_options,
									(char *[]){OPTIONS_WITH_NUM}, check_func))
		return (o_id);
	else if (find_options(&o_id, i_options,
									(char *[]){OPTIONS}, check_func))
		return (o_id);
	else if (find_options(&o_id, i_options,
									(char *[]){OPTIONS_EXTRA}, check_func))
		return (o_id);
	return (NO_OPTIONS);
}
