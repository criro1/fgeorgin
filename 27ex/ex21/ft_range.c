/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:29:33 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/08 16:04:44 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *arr;
	int i;
	int j;

	if (min >= max)
		return (NULL);
	arr = (int*)malloc(sizeof(int) * (max - min + 1));
	i = 0;
	j = min;
	while (j < max)
	{
		arr[i] = j;
		i++;
		j++;
	}
	return (arr);
}
