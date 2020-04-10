/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:25:53 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/06 14:34:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

#include "corewar.h"
/*
** Global variable
*/
typedef struct	s_op
{
	char		name[10];
	int			num_args;
	t_arg_type	type[3];
	int			code;
	int			cycle_to_exec;
	char		description[40];
	t_boolean	have_code_type_arg;
	int			x2;
	int			size_dir;
	void		(*exec)(t_carriage *m_carr, t_code *i_code, t_corewar *m_cor);
}				t_op;

const t_op		g_op_tab[18] =
{
	{{0}, 0, {0, 0, 0}, 0, 0, {0}, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "substraction", 1, 0, 4, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2, 0},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2, 0},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2, 0},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2, 0},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4, 0},
	{{0}, 0, {0, 0, 0}, 0, 0, {0}, 0, 0, 0, 0},
};

const t_arg_type	g_type_tab[2][3] =
{
	{T_REG, T_DIR, T_IND},
	{REG_SIZE, DIR_SIZE, IND_SIZE}
};

const int			g_options;

#endif
