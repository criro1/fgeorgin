/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_options_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:15:06 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 15:15:47 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_options_list	*malloc_options_list(char *i_name_options)
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
}

t_options_list			*new_options_list(char *i_options_name,
												int *m_index_arg, char **i_argv)
{
	void			*funcs_new_opt;
	t_options_list	*o_new;

	if (!(o_new = malloc_options_list(i_options_name)))
	{
		save_error_to_log("Options", i_options_name);
		return (NULL);
	}
	o_new->id = get_id_options(i_options_name);
	funcs_new_opt = (t_funcs_new_opt_obj){NEW_OPT_FUNCS};
	if (((t_func_new_opt_obj*)funcs_new_opt)[o_new->id])
	{
		o_new->option_obj =
			((t_func_new_opt_obj*)funcs_new_opt)[o_new->id](m_index_arg,
																		i_argv);
		if (errno)
		{
			save_error_to_log("Options object", i_options_name);
			destroy_options_list(&o_new);
		}
	}
	return (o_new);
}
