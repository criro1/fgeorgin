/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2020/02/04 13:41:29 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <stdio.h>

struct			s_op
{
	char		name[10];
	int			num_args;
	int			type[4];
	int			code;
	int			cycle_to_exec;
	char		description[40];
	int			code_type_arg;
	int			x2;
	int			size_dir;
	int			(*exec)(int*);
} ;

typedef	struct s_op	t_op;

typedef	enum	e_opers
{
	live = 1,
	ld = 2
}				t_opers;

int		jopa(int *test)
{
	printf("jopa\n");
	return (0);
}


t_op	g_op_tab[18] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4, jopa},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4, jopa},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4, jopa},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4, jopa},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "substraction", 1, 0, 4, jopa},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4, jopa},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4, jopa},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4, jopa},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2, jopa},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2, jopa},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2, jopa},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2, jopa},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4, jopa},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2, jopa},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2, jopa},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4, jopa},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int	test1(int x[4])
{
	printf("work |<%d><%d><%d><%d>|\n", x[0], x[1], x[2], x[3]);
	return (0);
}

int	main(void)
{
	int	i;

	i = 1;
	printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
	while (i < 17)
	{
		printf("| %-5s | num args = %2d | code = %#0.2x | cycle to exec = %4d | description = %-15.15s |  code_type_arg = %5s | x = %5s |\n",
				g_op_tab[i].name, g_op_tab[i].num_args, g_op_tab[i].code, g_op_tab[i].cycle_to_exec, g_op_tab[i].description,
				(g_op_tab[i].code_type_arg ? "True" : "False"), (g_op_tab[i].x2 ? "True" : "False"));
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
		++i;
	}
	int testim[4] = {33, 44, 55, 66};
	test1(testim);
	return (0);
}
