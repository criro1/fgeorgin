/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodarraydel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:42:18 by mwuckert          #+#    #+#             */
/*   Updated: 2019/05/04 14:42:20 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twodarraydel(void **twod_array)
{
	if (twod_array)
	{
		ft_delelemofarray(twod_array);
		ft_memdel((void**)&twod_array);
	}
}
