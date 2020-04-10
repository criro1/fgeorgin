/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:49:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/03 16:50:09 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

void	ft_normalize_num(unsigned *num, int *length)
{
	unsigned *start;
	unsigned *end;

	start = num;
	end = num + *length;
	while (start < end)
	{
		*(start + 1) += *start / BASE_LONG_NUM;
		*start %= BASE_LONG_NUM;
		++start;
	}
	if (*start >= BASE_LONG_NUM)
	{
		++(*length);
		*(start + 1) += *start / BASE_LONG_NUM;
		*start %= BASE_LONG_NUM;
	}
}
