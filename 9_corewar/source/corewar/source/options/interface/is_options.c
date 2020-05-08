/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 21:57:45 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/12 22:14:19 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_boolean	is_options(char *i_options)
{
	if (*i_options == SIGN_OPTIONS)
		return (True);
	return (False);
}
