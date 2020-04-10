/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 04:56:18 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/08 15:15:06 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_print(t_print *sp)
{
	ft_putstr("\n\nFLAGS:    ");
	ft_putnbr(sp->format.flags);
	ft_putstr("\nWIDTH:      ");
	ft_putnbr(sp->format.width);
	ft_putstr("\nPRECISION:  ");
	ft_putnbr(sp->format.precision);
	ft_putstr("\nSIZE:       ");
	ft_putnbr(sp->format.size);
	ft_putstr("\nTYPES:      ");
	ft_putnbr(sp->format.types);
	ft_putchar('\n');
}
