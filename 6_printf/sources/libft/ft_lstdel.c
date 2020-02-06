/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:11:43 by pnita             #+#    #+#             */
/*   Updated: 2019/04/18 19:11:45 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *,
size_t))
{
	t_list	*ptr;

	if (!alst || !*alst || !del)
		return ;
	ptr = (*alst)->next;
	while (ptr)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = ptr;
		ptr = ptr->next;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = 0;
}
