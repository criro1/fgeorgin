/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:41:56 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:41:59 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*create_str2(long int n)
{
	char	*s2;
	int		i;

	s2 = (char*)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i <= n)
		s2[i++] = '0';
	s2[i] = '\0';
	return (s2);
}

void		ft_reverse_str(char *s)
{
	int		i;
	int		j;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(s);
	j = len - 1;
	while (i < (len + 1) / 2)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

void		put_m_to_str(t_par par, unsigned long m)
{
	int		i;

	i = 64;
	while (i--)
		*(par.m++) = ((m >> i) & 1lu) + 48;
	*par.m = '\0';
}

void		str1_plus_str_num(char *s, char *str_num)
{
	int		sum;
	char	*s_tmp;

	sum = 0;
	while (*str_num)
	{
		s_tmp = s++;
		sum = sum + (*(str_num++) - 48) + ((*s_tmp) ? *s_tmp - 48 : 0);
		*(s_tmp++) = sum % 10 + 48;
		sum /= 10;
	}
	while (sum)
	{
		sum = sum + ((*s_tmp) ? *s_tmp - 48 : 0);
		*(s_tmp++) = sum % 10 + 48;
		sum /= 10;
	}
}

void		str2_plus_str_num(char *s, char *str_num, int size)
{
	int		sum;
	char	*s_tmp;

	s_tmp = s + size - 1;
	sum = 0;
	while (*str_num)
	{
		sum = sum + (*(str_num++) - 48) + (*s_tmp - 48);
		*(s_tmp--) = sum % 10 + 48;
		sum /= 10;
	}
	while (sum)
	{
		sum = sum + (*s_tmp - 48);
		*(s_tmp--) = sum % 10 + 48;
		sum /= 10;
	}
}
