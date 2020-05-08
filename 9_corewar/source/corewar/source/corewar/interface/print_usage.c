/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:08:55 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/25 18:46:56 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			print_synopsis(void)
{
	ft_printf("./corewar ");
	ft_printf("[-h | -help] [-d | -dump <nbr_cycles>] [-v | -visu] ");
	ft_printf("[-a | -aff]\n");
	ft_printf("\t\t  [-c | -client <ip server> [-port <port>] ");
	ft_printf("[-pass <password>]]\n");
	ft_printf("\t\t  [-s | -server [-port <port>] [-pass <password>] ");
	ft_printf("[-players <nbr_players>]]\n");
	ft_printf("\t\t  [[-n <number>] <champion1.cor>] <...>\n");
}

void				print_usage(void)
{
	ft_printf("usage:	");
	print_synopsis();
}
