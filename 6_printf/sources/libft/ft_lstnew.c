/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:02:21 by pnita             #+#    #+#             */
/*   Updated: 2019/04/16 22:02:23 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_lst_element_alloc(void const *content,
size_t content_size)
{
	void			*cont_out;
	unsigned char	*ptr_cont_out;
	unsigned char	*ptr;
	size_t			i;

	if (!(cont_out = (void*)malloc(content_size)))
		return (0);
	ptr_cont_out = (unsigned char*)cont_out;
	ptr = (unsigned char*)content;
	i = 0;
	while (i < content_size)
	{
		ptr_cont_out[i] = ptr[i];
		i++;
	}
	return (cont_out);
}

t_list			*ft_lstnew(void const *content,
size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		a->content = 0;
		a->content_size = 0;
	}
	else
	{
		if (!(a->content = ft_lst_element_alloc(content, content_size)))
		{
			free(a);
			a = 0;
			return (0);
		}
		a->content_size = content_size;
	}
	a->next = 0;
	return (a);
}
