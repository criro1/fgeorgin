/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:15:17 by pnita             #+#    #+#             */
/*   Updated: 2019/04/16 22:15:19 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	if (!alst || !(*alst) || !del)
		return ;
	del((void*)((*alst)->content), (*alst)->content_size);
	free(*alst);
	*alst = 0;
}
