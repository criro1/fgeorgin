/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:19:44 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/25 19:24:41 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_options_list	*pop_options(t_args_obj *m_args)
{
	t_options_list	*o_options;

	o_options = m_args->options;
	m_args->options = NULL;
	return (o_options);
}
