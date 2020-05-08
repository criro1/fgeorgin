/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_package_put_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:19:18 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/01 13:27:30 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*net_package_put_end(void *m_dst, int i_code_pakege)
{
	unsigned char	*o_iterator;
	unsigned		sign_end;

	o_iterator = m_dst;
	sign_end = PAKEGE_SIGN_END;
	o_iterator = ft_memcpy(o_iterator, &i_code_pakege, 4) + 4;
	o_iterator = ft_memcpy(o_iterator, &sign_end, 4) + 4;
	return ((void*)o_iterator);
}
