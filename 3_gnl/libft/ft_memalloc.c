/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:22:36 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/29 20:59:37 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *m;

	m = (void*)malloc(sizeof(void) * size);
	if (m == NULL)
		return (NULL);
	ft_memset(m, 0, size);
	return (m);
}
