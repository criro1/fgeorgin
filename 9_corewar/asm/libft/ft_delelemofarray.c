/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delelemofarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:16:36 by mwuckert          #+#    #+#             */
/*   Updated: 2019/01/14 08:27:54 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delelemofarray(void **array)
{
	if (array && *array)
	{
		if (*(array + 1))
			ft_delelemofarray(array + 1);
		ft_memdel(&*array);
	}
}
