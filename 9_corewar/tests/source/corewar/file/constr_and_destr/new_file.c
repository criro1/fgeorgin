/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:39:59 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/17 11:48:05 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_file		*new_file(char *i_path)
{
	t_file	*o_new;

	if (!(o_new = (t_file *)ft_memalloc(sizeof(t_file))))
		return (NULL);
	if (!(o_new->path = ft_strdup(i_path)))
	{
		ft_memdel((void**)&o_new);
		return (NULL);
	}
	return (o_new);
}
