/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:15:09 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/07/08 17:03:03 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_move(t_tetr *res)
{
	int		min_row;
	int		min_col;
	int		i;

	min_row = ft_min(res->row, 4);
	min_col = ft_min(res->col, 4);
	i = 0;
	while (i < 4)
	{
		res->row[i] -= min_row;
		res->col[i] -= min_col;
		i++;
	}
}

int			ft_createfig(char *buf, t_tetr *mas)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (mas[k].letter)
		k++;
	if (k > 25)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			mas[k].row[j] = i / 5;
			mas[k].col[j] = i % 5;
			j++;
		}
		i++;
	}
	mas[k].letter = 'A' + k;
	ft_move(&mas[k]);
	return (1);
}

int			ft_istetra(char *buf, int sh)
{
	int		i;
	int		con;

	i = 0;
	con = 0;
	sh = 0;
	while (buf[i] != '\0' || (buf[0] != '.' && buf[0] != '#'))
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			sh += 1;
		if (i > 0 && buf[i] == '#' && buf[i - 1] == '#')
			con++;
		if (i < 18 && buf[i] == '#' && buf[i + 1] == '#')
			con++;
		if (i < 14 && buf[i] == '#' && buf[i + 5] == '#')
			con++;
		if (i > 4 && buf[i] == '#' && buf[i - 5] == '#')
			con++;
		i++;
	}
	if ((con == 6 || con == 8) && ft_strlen(buf) >= 20 && sh == 4)
		return (1);
	return (0);
}

int			ft_checkfile(char *ac, t_tetr *mas)
{
	int		fd;
	char	buf[22];
	int		r;

	fd = open(ac, O_RDONLY);
	buf[0] = '\0';
	while ((r = read(fd, buf, 21)))
	{
		buf[r] = '\0';
		if (r < 20 || buf[r - 1] != '\n' || (!ft_istetra(buf, 0)))
		{
			close(fd);
			return (0);
		}
		if (!ft_createfig(buf, mas))
			return (0);
		if (r == 20)
			break ;
	}
	close(fd);
	return (ft_strlen(buf) == 20 ? 1 : 0);
}

int			main(int av, char **ac)
{
	t_tetr	lst[26];
	char	**map;

	ft_bzero(lst, sizeof(t_tetr) * 26);
	if (av != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	if (!ft_checkfile(ac[1], lst))
	{
		ft_putstr("error\n");
		return (0);
	}
	map = ft_solver(lst);
	ft_print_map(map);
	ft_destroy_map(map, ft_strlen(map[0]));
	return (0);
}
