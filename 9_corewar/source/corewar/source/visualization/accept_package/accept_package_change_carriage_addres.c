/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_package_change_carriage_addres.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:58:58 by astamm            #+#    #+#             */
/*   Updated: 2020/03/15 17:38:54 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	accept_package_change_carriage_addres(t_package *package,
							t_visu_carriagess *struct_carriages, t_visu *visu)
{
	int				id;
	unsigned char	*content;

	content = package->content;
	ft_memcpy(&id, content, 4);
	content += 4;
	ft_memcpy(&struct_carriages->carriages[id]->address, content, 4);
	visu_change_carriage_address(visu, struct_carriages->carriages[id]);
}
