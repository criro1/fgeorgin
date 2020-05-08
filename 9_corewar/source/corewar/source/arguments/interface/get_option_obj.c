/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:54:08 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/24 15:45:09 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*get_option_obj(t_options_list *i_options_lst, char *i_options)
{
	int				id_option;
	void			*option_obj;
	t_options_list	*iterator;

	if ((iterator = i_options_lst))
	{
		id_option = get_id_options(i_options);
		while (iterator)
		{
			if (iterator->id == id_option)
			{
				option_obj = iterator->option_obj;
				iterator->option_obj = NULL;
				return (option_obj);
			}
			iterator = iterator->next;
		}
	}
	else
		save_error_to_log("Can't get option obj", i_options);
	return (NULL);
}
