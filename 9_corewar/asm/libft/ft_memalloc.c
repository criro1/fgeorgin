/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:56:57 by mwuckert          #+#    #+#             */
/*   Updated: 2020/01/09 11:59:05 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void *new;

	new = 0;
	if (!(new = malloc(sizeof(*new) * size)))
		return (0);
	ft_bzero(new, size);
	return (new);
}
