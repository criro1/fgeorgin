/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 21:54:50 by forange-          #+#    #+#             */
/*   Updated: 2019/07/04 21:29:31 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int x)
{
	int start;
	int	end;
	int	ans;
	int mid;

	end = x;
	start = 1;
	if (x == 0 || x == 1)
		return (x);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == x)
			return (mid);
		if (mid * mid < x)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return (ans);
}
