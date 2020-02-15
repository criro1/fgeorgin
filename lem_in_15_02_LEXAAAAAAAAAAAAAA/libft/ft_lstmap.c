/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:25:18 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/02 18:22:24 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *p;
	t_list *begin;

	if (lst == NULL)
		return (NULL);
	begin = f(lst);
	if (begin == NULL)
		return (NULL);
	p = begin;
	lst = lst->next;
	while (lst != NULL)
	{
		p->next = f(lst);
		if (p->next == NULL)
		{
			free(p);
			return (NULL);
		}
		lst = lst->next;
		p = p->next;
	}
	return (begin);
}
