/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:02:58 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/07 14:23:39 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_options_list	*get_option_list(t_options_list *i_top, char *i_opt)
{
	t_options_list	*o_list;

	o_list = i_top;
	while (o_list)
	{
		if (o_list->name && o_list->name[0] == i_opt[0])
			return (o_list);
		o_list = o_list->next;
	}
	return (NULL);
}

static void				push_opt_list_to_options(t_options_list **m_opt,
														t_options_list *i_new)
{
	if (!(*m_opt))
		*m_opt = i_new;
	else
	{
		i_new->next = (*m_opt);
		(*m_opt) = i_new;
	}
}

static t_options_list	*new_list_option(char *i_opt_name, void *i_opt_obj)
{
	t_options_list	*o_new;

	if (!(o_new = (t_options_list *)ft_memalloc(sizeof(t_options_list))))
	{
		save_error_to_log("Options", i_opt_name);
		return (NULL);
	}
	if (!(o_new->name = ft_strdup(i_opt_name)))
	{
		save_error_to_log("Options->name", i_opt_name);
		ft_memdel((void**)&o_new);
		return (NULL);
	}
	o_new->id = get_id_options(i_opt_name);
	o_new->option_obj = i_opt_obj;
	return (o_new);
}

void					add_option(t_options_list **m_opt, char *i_opt_name,
																void *i_opt_obj)
{
	t_options_list	*new;
	t_options_list	*old_options;

	if ((old_options = get_option_list(*m_opt, i_opt_name)))
	{
		ft_memdel((void**)&old_options->option_obj);
		old_options->option_obj = i_opt_obj;
	}
	else if ((new = new_list_option(i_opt_name, i_opt_obj)))
		push_opt_list_to_options(m_opt, new);
}
