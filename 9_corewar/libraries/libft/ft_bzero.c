/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:27:42 by mwuckert          #+#    #+#             */
/*   Updated: 2020/01/25 21:04:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#define ONE_BYTE	8

static void	ft_bzero_by_words(void *mem, size_t words)
{
	unsigned long	*iterator_64;
	unsigned long	*end;

	end = (unsigned long *)mem + words;
	iterator_64 = (unsigned long *)mem;
	while (iterator_64 < end)
		*iterator_64++ = 0;
}

static void	ft_bzero_by_byte(void *mem, size_t byte)
{
	unsigned char	*iterator_8;
	unsigned char	*end;

	iterator_8 = (unsigned char *)mem;
	end = (unsigned char *)mem + byte;
	while (iterator_8 < end)
		*iterator_8++ = 0;
}

void		ft_bzero(void *s, size_t n)
{
	size_t			words;
	size_t			bytes;

	if ((words = n / 8))
	{
		ft_bzero_by_words(s, words);
		s = (unsigned char *)s + words * ONE_BYTE;
	}
	if ((bytes = n % ONE_BYTE))
		ft_bzero_by_byte(s, bytes);
}
