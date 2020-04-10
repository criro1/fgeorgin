/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:18:03 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/09 20:04:35 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	validation_options(t_valid_args *m_valid,
											t_valid_arg_func *valid_funcs)
{
	int			index_func;

	index_func = get_id_options(m_valid->argv[m_valid->current_arg] + 1);
	if (index_func < 0)
		errno = EINVAL;
	else
	{
		if (((func_valid_arg*)valid_funcs)[index_func])
			((func_valid_arg*)valid_funcs)[index_func](m_valid);
		if (!errno)
			++m_valid->current_arg;
	}
}

static void	validation_order_and_number_players(t_valid_args *m_valid)
{
	if (m_valid->amount_files < MIN_PLAYERS)
	{
		errno = EINVAL;
		ft_exit("No players");
	}
	if (m_valid->amount_files > MAX_PLAYERS)
	{
		errno = EINVAL;
		ft_exit("Too many players");
	}
	if (m_valid->order_files & (4294967295 << m_valid->amount_files))
	{
		errno = EINVAL;
		ft_exit("Invalid order players");
	}
}

t_boolean	validation_args(int argc, char **argv)
{
	t_valid_args	valid_obj;
	void			*validation_funcs;

	valid_obj = new_valid_obj(argc, argv);
	validation_funcs = (t_valid_arg_func){VALID_FUNCS};
	while (valid_obj.current_arg < argc &&
			valid_obj.amount_files <= MAX_PLAYERS)
	{
		if (argv[valid_obj.current_arg][0] == '-')
			validation_options(&valid_obj, validation_funcs);
		else if (is_suitable_file(argv[valid_obj.current_arg]))
		{
			++valid_obj.amount_files;
			++valid_obj.current_arg;
		}
		if (errno)
			ft_exit(valid_obj.argv[valid_obj.current_arg]);
	}
	validation_order_and_number_players(&valid_obj);
	ft_printf("validations_arg argc = %d %s\n", argc, *argv);
	return (True);
}
