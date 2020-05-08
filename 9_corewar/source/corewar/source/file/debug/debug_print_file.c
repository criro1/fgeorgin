/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:11:17 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:28:47 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_print_file(t_file *i_file, int indent, int i_amount_spaces)
{
	if (i_file)
	{
		print_space(i_amount_spaces);
		ft_printf("%-*s = %d\n", indent, "File fd", i_file->fd);
		print_space(i_amount_spaces);
		ft_printf("%-*s = %s\n", indent, "File path", i_file->path);
		print_space(i_amount_spaces);
		ft_printf("%-*s = %s\n", indent, "File open",
												i_file->open ? "Yes" : "No");
		print_space(i_amount_spaces);
		ft_printf("%-*s = %s\n", indent,
									"File entry", i_file->entry ? "Yes" : "No");
		print_space(i_amount_spaces);
		ft_printf("%-*s = %ld\n", indent, "File size", i_file->size);
	}
	else
	{
		print_space(i_amount_spaces);
		ft_printf("%-*s = %s\n", indent, "File ", "NULL");
	}
}
