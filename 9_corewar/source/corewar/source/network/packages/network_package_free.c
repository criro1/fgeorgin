/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_package_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:41:26 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/05 17:11:36 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	network_package_free(t_pack_net *m_pakege)
{
	ft_memdel((void**)&m_pakege->data);
	ft_bzero(m_pakege, sizeof(t_pack_net));
}
