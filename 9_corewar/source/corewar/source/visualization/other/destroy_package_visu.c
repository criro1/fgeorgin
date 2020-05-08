/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_package_visu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:42:11 by astamm            #+#    #+#             */
/*   Updated: 2020/03/15 17:25:36 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_package_visu(t_package *package)
{
	ft_memdel((void**)&package->content);
	package->code_package = 0;
	package->size_package = 0;
}
