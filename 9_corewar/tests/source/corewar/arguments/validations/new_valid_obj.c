/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_valid_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:57:16 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/03 17:15:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_valid_args	new_valid_obj(int argc, char **argv)
{
	t_valid_args	o_new;

	ft_bzero(&o_new, sizeof(t_valid_args));
	o_new.current_arg = 1;
	o_new.argc = argc;
	o_new.argv = argv;
	return (o_new);
}
