/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:40:29 by forange-          #+#    #+#             */
/*   Updated: 2019/07/04 19:46:30 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_min(int *mas, size_t size)
{
	int		res;
	size_t	i;

	i = 1;
	res = mas[0];
	while (i < size)
	{
		if (mas[i] < res)
			res = mas[i];
		i++;
	}
	return (res);
}
