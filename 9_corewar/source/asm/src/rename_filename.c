/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 02:23:40 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/17 02:23:52 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*rename_filename(char *filename)
{
	char		*new;
	char		*save;
	int			count;
	char		*dot;

	count = 0;
	save = filename;
	dot = ft_strrchr(save, '.');
	new = ft_strnew(0);
	new = ft_strcpy_upto_ptr(new, save, dot);
	new = ft_strjoin_free(new, ".cor");
	return (new);
}
