/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:27:33 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/17 14:30:51 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_line(char c, int size, t_boolean new_line)
{
	int		counter;

	counter = 0;
	while (counter < size)
	{
		ft_printf("%c", c);
		++counter;
	}
	if (new_line)
		ft_printf("\n");
}
