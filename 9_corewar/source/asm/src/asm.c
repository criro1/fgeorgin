/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:20:28 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 15:44:58 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	if (ac == 2)
		assemble(av[1]);
	else
		ft_printf("Usage: ./asm <file.s>\n");
	exit(EXIT_SUCCESS);
}
