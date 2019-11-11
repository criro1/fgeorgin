/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:46:22 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/02 17:42:26 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;

	if (alst == NULL || (*alst) == NULL)
		return ;
	while ((*alst) != NULL)
	{
		p = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = p;
	}
	(*alst) = NULL;
}
