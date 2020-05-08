/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_package_put_header.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:03:22 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/05 22:55:40 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*net_package_put_header(void *m_dst, int size_cont, int code_pak)
{
	unsigned char	*o_iterator;
	unsigned		begin_sign;

	o_iterator = m_dst;
	begin_sign = PAKEGE_SIGN_BEGIN;
	o_iterator = ft_memcpy(o_iterator, &begin_sign, 4) + 4;
	o_iterator = ft_memcpy(o_iterator, &size_cont, 4) + 4;
	o_iterator = ft_memcpy(o_iterator, &code_pak, 4) + 4;
	return ((void*)o_iterator);
}
