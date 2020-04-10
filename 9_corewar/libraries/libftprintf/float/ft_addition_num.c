/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:32:42 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/03 15:20:39 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"

void	ft_addition_num(unsigned *num1, unsigned *num2, int *l1, int *l2)
{
	unsigned	*end;
	unsigned	*n;

	if (!*l1)
		*l1 = *l2;
	n = num1;
	end = num2 + *l2;
	while (num2 <= end)
		*num1++ += *num2++;
	ft_normalize_num(n, l1);
}
