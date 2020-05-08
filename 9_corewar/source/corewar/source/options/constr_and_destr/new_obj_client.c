/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_obj_client.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:47:41 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:18:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_boolean	is_extra_options_server(char *i_opt)
{
	if (!ft_strcmp(i_opt, "-port") || !ft_strcmp(i_opt, "-pass"))
		return (True);
	return (False);
}

static void			skip_extra_options_server(int *m_index_arg, char **i_argv)
{
	++(*m_index_arg);
	while (is_extra_options_server(i_argv[*m_index_arg++]))
		(*m_index_arg)++;
}

static void			set_extra_options_server(int *m_i_arg, char **i_argv,
																t_client *i_s)
{
	int	index;

	index = *m_i_arg;
	while (i_argv[index] && is_extra_options_server(i_argv[index]))
	{
		if (!ft_strcmp("-port", i_argv[index]))
			ft_strcpy(i_s->port, i_argv[++index]);
		else if (!ft_strcmp("-pass", i_argv[index]))
			ft_strcpy(i_s->pass, i_argv[++index]);
		++index;
	}
	*m_i_arg = index - 1;
}

void				*new_obj_client(int *m_index_arg, char **i_argv)
{
	t_client	*o_new;

	++(*m_index_arg);
	if (!(o_new = (t_client*)ft_memalloc(sizeof(t_client))))
	{
		save_error_to_log("Options client", E_NO_MEM);
		skip_extra_options_server(m_index_arg, i_argv);
	}
	else
	{
		ft_strcpy(o_new->ip_server, i_argv[(*m_index_arg)++]);
		set_extra_options_server(m_index_arg, i_argv, o_new);
	}
	return ((void*)o_new);
}
