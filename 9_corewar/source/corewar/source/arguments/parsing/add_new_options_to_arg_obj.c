/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_options_to_arg_obj.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:33:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 15:13:01 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	add_new_player_with_options(t_players *m_players, int *m_index_arg,
																char **i_argv)
{
	t_player	*new;
	char		*path;
	int			order;

	++(*m_index_arg);
	order = ft_atoi(i_argv[(*m_index_arg)++]) - 1;
	path = i_argv[(*m_index_arg)];
	if (!(new = new_player(path, order)))
		save_error_to_log("Player with option", i_argv[*m_index_arg]);
	else
		push_player_to_players(m_players, new, new->order);
}

static void	add_new_options_only(t_args_obj *m_args, int *m_index_arg,
																char **i_argv)
{
	void			*new_option_obj;
	void			*funcs_new_opt;
	char			*options_name;
	int				id_option;

	options_name = i_argv[*m_index_arg] + 1;
	new_option_obj = NULL;
	id_option = get_id_options(options_name);
	funcs_new_opt = (t_funcs_new_opt_obj){NEW_OPT_FUNCS};
	if (((t_func_new_opt_obj*)funcs_new_opt)[id_option])
	{
		new_option_obj =
		((t_func_new_opt_obj*)funcs_new_opt)[id_option](m_index_arg, i_argv);
		if (errno)
			save_error_to_log("Options", options_name);
		else
			add_option(&m_args->options, options_name, new_option_obj);
	}
	else
		add_option(&m_args->options, options_name, NULL);
}

void		add_new_options_to_arg_obj(t_args_obj *m_args, int *m_index_arg,
																char **i_argv)
{
	char			*options_name;

	options_name = i_argv[*m_index_arg] + 1;
	if (is_options_player(options_name))
		add_new_player_with_options(m_args->players, m_index_arg, i_argv);
	else
		add_new_options_only(m_args, m_index_arg, i_argv);
}
