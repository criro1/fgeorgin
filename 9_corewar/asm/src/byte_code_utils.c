/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_code_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:25:45 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 05:14:22 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define UNSIGNED_SIZE	(sizeof(unsigned))

unsigned			number_reverse_mem(unsigned i_origin_num)
{
	int				current_byte;
	unsigned		o_reverse_num;
	unsigned char	*mem_origin;
	unsigned char	*mem_reverse;

	o_reverse_num = 0;
	mem_origin = (unsigned char*)&i_origin_num;
	mem_reverse = (unsigned char*)&o_reverse_num;
	current_byte = 0;
	while (current_byte < (int)UNSIGNED_SIZE)
	{
		mem_reverse[(UNSIGNED_SIZE - 1) - current_byte] =
			mem_origin[current_byte];
		++current_byte;
	}
	return (o_reverse_num);
}

/*
**	increasing bc depending on instruction's arguments
*/

void				get_bc_from_args(t_token_node *node, unsigned *bc)
{
	if (node->arg1 == reg)
		*bc += 1;
	else if (node->arg1 == indir)
		*bc += 2;
	else if (node->arg1 == dir)
		*bc += node->next->dir_size;
	if (node->arg2 == reg)
		*bc += 1;
	else if (node->arg2 == indir)
		*bc += 2;
	else if (node->arg2 == dir)
		*bc += node->next->next->dir_size;
	if (node->arg3 == reg)
		*bc += 1;
	else if (node->arg3 == indir)
		*bc += 2;
	else if (node->arg3 == dir)
		*bc += node->next->next->next->dir_size;
	*bc += 1;
}

unsigned			get_number_of_args(t_token_node *node)
{
	unsigned		counter;

	counter = 0;
	if (node->arg1 == reg || node->arg1 == dir || node->arg1 == indir)
		counter++;
	if (node->arg1 == reg || node->arg1 == dir || node->arg1 == indir)
		counter++;
	if (node->arg2 == reg || node->arg2 == dir || node->arg2 == indir)
		counter++;
	if (node->arg3 == reg || node->arg3 == dir || node->arg3 == indir)
		counter++;
	return (counter);
}

char				*ft_strcpy_upto_ptr(char *new, char *save, char *dot)
{
	char			*tmp;
	unsigned		count;
	unsigned		i;

	count = 0;
	i = -1;
	tmp = save;
	while (tmp++ != dot)
		count++;
	ft_memdel((void**)&new);
	if (!(new = (char*)malloc(sizeof(char) * (count + 1))))
		exit(1);
	while (++i < count)
		new[i] = save[i];
	new[i] = '\0';
	return (new);
}
