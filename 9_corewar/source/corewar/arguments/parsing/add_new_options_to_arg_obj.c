/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_options_to_arg_obj.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:33:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/18 12:27:54 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*static t_options_list	*malloc_options_list(char *i_name_options)
{
	t_options_list	*o_new;

	if (!(o_new = (t_options_list *)ft_memalloc(sizeof(t_options_list))))
	{
		save_error_to_log("Options", i_name_options);
		return (NULL);
	}
	if (!(o_new->name = ft_strdup(i_name_options)))
	{
		save_error_to_log("Options->name", i_name_options);
		return (o_new);
	}
	return (o_new);
}*/

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

/*static void	push_opt_list_to_args_obj(t_args_obj *m_args, t_options_list *i_new)
{
	if (!m_args->options)
		m_args->options = i_new;
	else
	{
		i_new->next = m_args->options;
		m_args->options = i_new;
	}
}*/

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
	if (((func_new_opt_obj*)funcs_new_opt)[id_option])
	{
		new_option_obj =
		((func_new_opt_obj*)funcs_new_opt)[id_option](m_index_arg, i_argv);
		if (errno)
			save_error_to_log("Options", options_name);
		else
		{
			add_option(&m_args->options, options_name, new_option_obj);

		/*	old_options = get_option_list(m_args->options, options_name);
			ft_memdel((void**)&old_options->option_obj);
			old_options->option_obj = new_option_obj; */
		}
	}
	else
		add_option(&m_args->options, options_name, NULL);
/*	if (!(new = malloc_options_list(options_name)))
		return ;
	new->id = get_id_options(options_name);
	funcs_new_opt = (t_funcs_new_opt_obj){NEW_OPT_FUNCS};
	if (((func_new_opt_obj*)funcs_new_opt)[new->id])
	{
		new->option_obj =
			((func_new_opt_obj*)funcs_new_opt)[new->id](m_index_arg, i_argv);
		if (errno)
		{
			save_error_to_log("Options->option_obj", options_name);
			destroy_options_list(&new);
		}
	}
	if (new)
		push_opt_list_to_args_obj(m_args, new);
*/
}

void	add_new_options_to_arg_obj(t_args_obj *m_args, int *m_index_arg,
																char **i_argv)
{
	char			*options_name;

	options_name = i_argv[*m_index_arg] + 1;
	if (is_options_player(options_name))
		add_new_player_with_options(m_args->players, m_index_arg, i_argv);
	else
		add_new_options_only(m_args, m_index_arg, i_argv);
}
