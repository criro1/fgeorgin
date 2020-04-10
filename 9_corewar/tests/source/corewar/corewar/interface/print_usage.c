/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:08:55 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/16 18:28:25 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_usage(void)
{
	ft_printf("usage:	");
	ft_printf("./corevar  [-dump nbr_cycles] [[-n number] <champion file>]\n");
	ft_printf("	Max players = %d\n", MAX_PLAYERS);
	ft_printf("	Min players = %d\n", MIN_PLAYERS);
}
