/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_fetch_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:14:06 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/06 20:31:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	parse_tdir(t_code *m_code)
{
	if (m_code->arg_type[flag_type][arg1] & T_DIR)
		m_code->arg_type[size_arg][arg1] = g_op_tab[m_code->oper].size_dir;
	else if (m_code->arg_type[flag_type][arg1])
		m_code->arg_type[size_arg][arg1] =
			g_type_tab[size_arg][m_code->arg_type[code_arg][arg1] - 1];
	if (m_code->arg_type[flag_type][arg2] & T_DIR)
		m_code->arg_type[size_arg][arg2] = g_op_tab[m_code->oper].size_dir;
	else if (m_code->arg_type[flag_type][arg2])
		m_code->arg_type[size_arg][arg2] =
			g_type_tab[size_arg][m_code->arg_type[code_arg][arg2] - 1];
	if (m_code->arg_type[flag_type][arg3] & T_DIR)
		m_code->arg_type[size_arg][arg3] = g_op_tab[m_code->oper].size_dir;
	else if (m_code->arg_type[flag_type][arg3])
		m_code->arg_type[size_arg][arg3] =
			g_type_tab[size_arg][m_code->arg_type[code_arg][arg3] - 1];
}

static void			parse_arg_type_code(t_code *m_code,
												unsigned char i_arg_type_code)
{
	m_code->arg_type[code_arg][arg1] = i_arg_type_code >> 6;
	m_code->arg_type[code_arg][arg2] = 0x03 & (i_arg_type_code >> 4);
	m_code->arg_type[code_arg][arg3] = 0x03 & (i_arg_type_code >> 2);
	if (m_code->arg_type[code_arg][arg1])
		m_code->arg_type[flag_type][arg1] =
			g_type_tab[flag_type][m_code->arg_type[code_arg][arg1] - 1];
	if (m_code->arg_type[code_arg][arg2])
		m_code->arg_type[flag_type][arg2] =
			g_type_tab[flag_type][m_code->arg_type[code_arg][arg2] - 1];
	if (m_code->arg_type[code_arg][arg3])
		m_code->arg_type[flag_type][arg3] =
			g_type_tab[flag_type][m_code->arg_type[code_arg][arg3] - 1];
	parse_tdir(m_code);
}

static int			fetch_code_arg_type(t_memory *i_mem, t_code *m_code,
																	int i_adrr)
{
	unsigned char	test;
	int				o_read_byte;

	o_read_byte = 0;
	test = 0;
	if (g_op_tab[m_code->oper].have_code_type_arg)
	{
		memory_read(i_mem, i_adrr, &test, SIZE_ARG_TYPE_CODE);
		parse_arg_type_code(m_code, test);
		o_read_byte = SIZE_ARG_TYPE_CODE;
	}
	else
	{
		m_code->arg_type[flag_type][arg1] = g_op_tab[m_code->oper].type[arg1];
		m_code->arg_type[size_arg][arg1] = g_op_tab[m_code->oper].size_dir;
	}
	m_code->size += o_read_byte;
	return (o_read_byte);
}

static void			calc_code_size(t_code *m_code)
{
	t_args			arg;

	arg = first_arg;
	while (arg < (t_args)g_op_tab[m_code->oper].num_args)
		m_code->size += m_code->arg_type[size_arg][arg++];
}

t_code				carriage_fetch_code(t_carriage *m_carr, t_memory *i_mem)
{
	t_code			o_code;
	int				curr_addr;

	ft_bzero(&o_code, sizeof(t_code));
	o_code.oper = m_carr->code;
	if (operation_valid_code_oper(o_code.oper))
	{
		o_code.valid = True;
		curr_addr = m_carr->address + SIZE_OPER_CODE;
		o_code.size = SIZE_OPER_CODE;
		curr_addr += fetch_code_arg_type(i_mem, &o_code, curr_addr);
		if (operation_valid_code_type_arg(&o_code))
			operation_fetch_args(i_mem, curr_addr, &o_code);
		calc_code_size(&o_code);
	}
	else
		o_code.size = 1;
	return (o_code);
}
