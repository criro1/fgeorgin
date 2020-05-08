/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <astamm@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:07:29 by artem             #+#    #+#             */
/*   Updated: 2020/04/25 18:48:25 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	print_server_mod(void)
{
	ft_printf("\n\t-s, -server <champion.cor> [-port <port>] ");
	ft_printf("[-pass <password>] [-players <number players>]\n");
	ft_printf("\t  run server mod. This mod is designed for ");
	ft_printf("playing online. You can choose a champion\n");
	ft_printf("\t  who will play for you on the remote server. In ");
	ft_printf("this mod, you can choose one champion or \n");
	ft_printf("\t  without him. You can also specify the ");
	ft_printf("connection port using the additional option\n");
	ft_printf("\t  -port <port> (default 3490). To set ");
	ft_printf("a password use -pass <password>. You can\n");
	ft_printf("\t  the number of players using using -players ");
	ft_printf("<number players>. To start the game, wait for all\n");
	ft_printf("\t  players to connect or press any key.\n");
}

static void			print_mods(void)
{
	ft_printf("\n\t-v, -visu\n");
	ft_printf("\t  run visual mod.\n");
	ft_printf("\n\t-c, -client <ip server> <champion.cor> ");
	ft_printf("[-port <port>] [-pass <password>]\n");
	ft_printf("\t  run client mod. This mod is designed for ");
	ft_printf("playing online. You must choose a player\n");
	ft_printf("\t  who will play for you on the remote server. In ");
	ft_printf("this mod you can choose only one champion.\n");
	ft_printf("\t  You can also specify the connection port using ");
	ft_printf("the additional option -port <port> (default 3490).\n");
	ft_printf("\t  if a password is set on the server, you must ");
	ft_printf("specify it using the -pass <password> option.\n");
	print_server_mod();
}

static void			print_options(void)
{
	ft_printf("\t-dump <nbr_cycles>\n");
	ft_printf("\t  at the end of nbr_cycles of executions,");
	ft_printf("dump the memory on the standard output\n");
	ft_printf("\t  and quit the game. The memory dumped in ");
	ft_printf("the hexadecimal format with\n");
	ft_printf("\t  32 octets per line.\n");
	ft_printf("\n\t-d <nbr_cycles>\n");
	ft_printf("\t  the same as -dump, but 64 octets per line.\n");
	ft_printf("\n\t-n <number> <champion.cor>\n");
	ft_printf("\t  sets the number of the next player. If non-existent, ");
	ft_printf("the player will have the next\n");
	ft_printf("\t  available number in the order of the parameters. ");
	ft_printf("The last player will have the first\n");
	ft_printf("\t  process in the order of execution.\n");
	ft_printf("\n\t-a, -aff\n");
	ft_printf("\t  prints output from \"aff\" (Default is to hide it)\n");
}

void				print_help(void)
{
	print_usage();
	ft_printf("\n OPTIONS\n");
	print_options();
	ft_printf("\n MODS\n");
	print_mods();
}
