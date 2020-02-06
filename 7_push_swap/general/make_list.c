/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:02:00 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/11/04 15:21:03 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long long		ft_atolli(const char *str)
{
	int			i;
	long int	num;
	int			s;

	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	s = ((str[i] == '-') ? -1 : 0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((s == -1) ? -num : num);
}

int				ft_num_of_digit(char *s)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (ft_isdigit(s[i]))
	{
		res++;
		i++;
	}
	return (res);
}

t_arr			*ft_new(char *s, int *num, int j)
{
	int		i;
	int		check;
	t_arr	*tmp;

	i = 0;
	if (ft_atolli(s) >= 2147483648 || ft_atolli(s) <= -2147483649)
		return (NULL);
	if (ft_num_of_digit(s) > 10)
		return (NULL);
	check = ft_atoi(s);
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (check == 0 && s[i] != '0' && s[i + 1] != '\0')
		return (NULL);
	while (s[i] != '\0')
		if (!(ft_strchr("0123456789 ", s[i++])))
			return (NULL);
	if (ft_strnbr(num, check, j) == 0)
		return (NULL);
	tmp = (t_arr*)malloc(sizeof(t_arr));
	tmp->n = check;
	tmp->next = NULL;
	return (tmp);
}

void			ft_if_head(t_arr **head, t_arr **tmp, t_arr **p)
{
	if (!(*head))
	{
		*p = *tmp;
		*head = *p;
	}
	else
	{
		(*p)->next = *tmp;
		*p = (*p)->next;
	}
}

t_arr			*ft_nums(t_arr *head, int j, char **av, int *num)
{
	int		i;
	t_arr	*tmp;
	t_arr	*p;
	char	**split;

	while (*av)
	{
		i = 0;
		split = ft_strsplit(*av, ' ');
		while (split[i])
		{
			if ((tmp = ft_new(split[i], num, j)) == NULL)
				return (ft_free(head, split));
			num[j++] = tmp->n;
			ft_if_head(&head, &tmp, &p);
			i++;
		}
		ft_free(NULL, split);
		av++;
	}
	num[j] = j;
	return (head);
}
