/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:45:10 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/31 10:42:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_print_player(t_player *i_player, int indent, int i_spaces)
{
	debug_print_file(i_player->file, indent, i_spaces + 2);
	print_space(i_spaces);
	ft_printf("%-*s = %s\n", indent,
				"Name", (i_player->name ? i_player->name : "NULL"));
	print_space(i_spaces);
	ft_printf("%-*s = %s\n", indent,
				"Comment", (i_player->name ? i_player->comment : "NULL"));
	print_space(i_spaces);
	ft_printf("%-*s = %d\n", indent, "Order", i_player->order);
	print_space(i_spaces);
	ft_printf("%-*s = %s\n", indent,
				"Mem_champion", (*i_player->mem_champion ? "Yes" : "No"));
	print_space(i_spaces);
	ft_printf("%-*s = %d\n", indent, "Champ size", i_player->size_bytes);
	print_memory(i_player->mem_champion, i_player->size_bytes);
}
