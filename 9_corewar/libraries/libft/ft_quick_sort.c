/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:45:34 by wmaykit           #+#    #+#             */
/*   Updated: 2019/11/24 21:13:27 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap_num(int *n1, int *n2)
{
	int		tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

static void	ft_sort(int *start, int *pivot)
{
	int		*left;
	int		*right;
	int		key;

	key = 0;
	left = start;
	right = pivot - 1;
	while (left <= right && !key)
	{
		while (left < pivot && *left < *pivot)
			++left;
		while (right > left && !(*right < *pivot))
			--right;
		if (left < right)
			ft_swap_num(left, right);
		if (left == right && (key += 1))
			ft_swap_num(left, pivot);
	}
	if (pivot - start > 0)
		ft_sort(start, left - 1);
	if (pivot - left > 0)
		ft_sort(left + 1, pivot);
}

void		ft_quick_sort(int *arry, int element)
{
	ft_sort(arry, arry + (element - 1));
}
