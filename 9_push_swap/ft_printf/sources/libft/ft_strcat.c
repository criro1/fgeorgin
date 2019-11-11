/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:41:01 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/15 21:12:19 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (s1[i] != '\0')
		i++;
	s = 0;
	while (s2[s] != '\0')
	{
		s1[i + s] = s2[s];
		s++;
	}
	s1[i + s] = '\0';
	return (s1);
}
