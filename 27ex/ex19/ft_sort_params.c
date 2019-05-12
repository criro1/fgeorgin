/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:56:56 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/08 15:57:25 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1[0] != '\0' && s2[0] == '\0')
		return (1);
	else if (s1[0] == '\0' && s2[0] != '\0')
		return (-1);
	else
	{
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] > s2[i])
				return (1);
			else if (s1[i] < s2[i])
				return (-1);
			else if (s1[i + 1] != '\0' && s2[i + 1] == '\0')
				return (1);
			else if (s1[i + 1] == '\0' && s2[i + 1] != '\0')
				return (-1);
			i++;
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	char	*a;

	i = 2;
	while (i < ac)
	{
		if (ft_strcmp(av[i], av[i - 1]) < 0)
		{
			a = av[i];
			av[i] = av[i - 1];
			av[i - 1] = a;
			i = 1;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
