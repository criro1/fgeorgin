/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_in_parse_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 08:18:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 08:19:11 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			func_reg_char(t_pa **pa, char **ptr,
										t_token_list **token_list)
{
	ft_ptr_register_char(&(*pa)->right, ptr, token_list);
	ft_arg_amount_1(token_list, &(*pa)->arg_amount, &(*pa)->save);
}

void			func_direct_char(t_pa **pa, char *ptr,
										t_token_list **token_list)
{
	ft_if_ptr_direct_char(token_list, &(*pa)->right, ptr);
	ft_arg_amount_2(token_list, &(*pa)->arg_amount, &(*pa)->save, (*pa)->instr);
}

void			func_label_char(t_pa **pa, char *ptr,
										t_token_list **token_list)
{
	ft_if_ptr_label_char(token_list, &(*pa)->right, ptr);
	ft_arg_amount_3(token_list, &(*pa)->arg_amount, &(*pa)->save);
}
