/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_obj_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:25:18 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/22 14:35:38 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_boolean	is_extra_options_server(char *i_opt)
{
	if (!ft_strcmp(i_opt, "-port") || !ft_strcmp(i_opt, "-pass") ||
			!ft_strcmp(i_opt, "-players"))
		return (True);
	return (False);
}

static void			skip_extra_options_server(int *m_index_arg, char **i_argv)
{
	while (is_extra_options_server(i_argv[*m_index_arg++]))
		(*m_index_arg)++;
}

static void			set_extra_options_server(int *m_i_arg, char **i_argv,
																t_server *i_s)
{
	int	index;

	index = *m_i_arg;
	while (i_argv[index] && is_extra_options_server(i_argv[index]))
	{
		if (!ft_strcmp("-port", i_argv[index]))
			ft_strcpy(i_s->port, i_argv[++index]);
		else if (!ft_strcmp("-pass", i_argv[index]))
			ft_strcpy(i_s->pass, i_argv[++index]);
		else if (!ft_strcmp("-players", i_argv[index]))
			i_s->amount_players = ft_atoi(i_argv[++index]);
		++index;
	}
	*m_i_arg = index - 1;
}

void				*new_obj_server(int *m_index_arg, char **i_argv)
{
	t_server	*o_new;

	++(*m_index_arg);
	if (!(o_new = (t_server*)ft_memalloc(sizeof(t_server))))
	{
		save_error_to_log("Options ", E_NO_MEM);
		skip_extra_options_server(m_index_arg, i_argv);
	}
	else
		set_extra_options_server(m_index_arg, i_argv, o_new);
	return ((void*)o_new);
}
