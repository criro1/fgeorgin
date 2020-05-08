/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:33:59 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/25 18:06:52 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op		g_op_tab[18] =
{
	{{0}, 0, {0, 0, 0}, 0, 0, {0}, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4, operation_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4, operation_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4, operation_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4,
		operation_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "substraction", 1, 0, 4,
		operation_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4, operation_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4, operation_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4, operation_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2, operation_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2, operation_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2, operation_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2, operation_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4,
		operation_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2, operation_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2, operation_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4, operation_aff},
	{{0}, 0, {0, 0, 0}, 0, 0, {0}, 0, 0, 0, 0},
};

t_arg_type g_type_tab[2][3] =
{
	{T_REG, T_DIR, T_IND},
	{1, 4, 2}
};

unsigned int g_options = 0;

static t_boolean	is_help_options(char *str)
{
	if (*str == '-' &&
			((str[1] == 'h' && !str[2]) || !ft_strcmp(str + 1, "help")))
		return (True);
	return (False);
}

int					main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (is_help_options(argv[1]))
			print_help();
		else
			corewar(argc, argv);
	}
	else
		print_usage();
	return (EXIT_SUCCESS);
}
