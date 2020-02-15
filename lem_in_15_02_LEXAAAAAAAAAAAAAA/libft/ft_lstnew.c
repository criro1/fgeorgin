/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:37:00 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/02 17:57:18 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	p = (t_list*)malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	if (content == NULL)
	{
		p->content = NULL;
		p->content_size = 0;
		p->next = NULL;
		return (p);
	}
	p->content = ft_memalloc(content_size);
	if (p->content == NULL)
		return (NULL);
	p->content_size = content_size;
	ft_memcpy(p->content, content, content_size);
	p->next = NULL;
	return (p);
}
