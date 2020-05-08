/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args_types_code_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:00:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 02:07:43 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_args_types_code_fd(t_token_node *node, int fd,
												unsigned *curr_bc_tmp)
{
	int			types_code;

	types_code = 0;
	*curr_bc_tmp += 1;
	types_code = (node->arg1 == reg) ? 1 : 0;
	if (node->arg1 == dir)
		types_code = 2;
	else if (node->arg1 == indir)
		types_code = 3;
	types_code <<= 2;
	if (node->arg2 == reg)
		types_code |= 1;
	else if (node->arg2 == dir)
		types_code |= 2;
	else if (node->arg2 == indir)
		types_code |= 3;
	types_code <<= 2;
	if (node->arg3 == reg)
		types_code |= 1;
	else if (node->arg3 == dir)
		types_code |= 2;
	else if (node->arg3 == indir)
		types_code |= 3;
	types_code <<= 2;
	write(fd, &types_code, 1);
}
