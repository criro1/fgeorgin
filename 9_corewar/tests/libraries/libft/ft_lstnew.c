/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:40:37 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/26 23:50:51 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return (0);
	if (!(content && content_size))
	{
		(*new).content = 0;
		(*new).content_size = 0;
		(*new).next = 0;
		return (new);
	}
	if (!((*new).content = ft_memalloc(sizeof(*content) * content_size)))
		return (0);
	ft_memcpy((*new).content, content, content_size);
	(*new).content_size = content_size;
	(*new).next = 0;
	return (new);
}
