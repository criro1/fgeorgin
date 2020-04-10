/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 12:20:53 by astamm            #+#    #+#             */
/*   Updated: 2019/11/17 15:08:01 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len + 1 == 0)
		return (0);
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
