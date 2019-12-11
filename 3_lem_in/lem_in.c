/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:37:35 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/12/08 19:37:37 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	number_of_ants(t_map *map, char *line)
{
	if (!ft_strcmp(line, ft_itoa(ft_atoi(line))))
	{
		printf("in number_of_ants = %s\n", line);
		map->num_ants = ft_atoi(line);
		if (map->num_ants <= 0)
		{
			free(map);
			free(line);
			write(2, "Error\n", 6);
			exit(0);
		}
		map->data = 1;
	}
	else
	{
		free(map);
		free(line);
		write(2, "Error\n", 6);
		exit(0);
	}
}

int		check_x_y(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_hash(char *s)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (s[i] != '\0')
	{
		res = res * 7 + s[i];
		i++;
	}
	return (res);
}

void	the_room(t_map *map, char *line, int sea)
{
	char	**arr;
	int		n;

	printf("in the_room = %s\n", line);//fdsnioghueowijhgueijewr
	arr = ft_strsplit(line, ' ');
	if (arr[3] != NULL || !check_x_y(arr[1]) || !check_x_y(arr[2]))
	{
		free(map);
		free(line);
		write(2, "Error\n", 6);
		exit(0);
	}
	n = ft_find_hash(arr[0]);
	map->room[n].name = ft_strdup(arr[0]);
	map->room[n].x = ft_atoi(arr[1]);
	map->room[n].y = ft_atoi(arr[2]);
	if (sea == 0)
		map->start = n;
	else if (sea == 1)
		map->end = n;
	map->data = 2;
}

void	ft_sharp(t_map *map, char *line, int fd) //fegrijfoekpjwighruiifjwodijo
{
	char se;

	printf("in ft_sharp = %s\n", line);
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
	{
		se = line[2];
		free(line);
		// fd = 0;
		get_next_line(fd, &line);//dwqqwdqwdqwdwqdqwdqwdqwdqw
		if (line[0] != 'L')
			the_room(map, line, (se == 's' ? 0 : 1));/* 0 - start, 1 - end, 2 - another */
		else
		{
			free(map);
			free(line);
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}

void	the_links(t_map *map, char *line)
{
	char **ar;
	int	n0;
	int n1;

	printf("in the_links = %s\n", line);
	ar = ft_strsplit(line, '-');
	n0 = ft_find_hash(ar[0]);
	n1 = ft_find_hash(ar[1]);
	if (ar[2] != NULL || !(map->room[n0].name) || !(map->room[n1].name))
	{
		free(map);
		free(line);
		write(2, "Error\n", 6);
		exit(0);
	}
	if (!map->room[n0].links)
		map->room[n0].links = (char**)ft_memalloc(sizeof(char*));
	map->room[n0].links[map->room[n0].curr_link] = ft_strdup(ar[1]);
	(map->room[n0].curr_link)++;
	if (!map->room[n1].links)
		map->room[n1].links = (char**)ft_memalloc(sizeof(char*));
	map->room[n1].links[map->room[n1].curr_link] = ft_strdup(ar[0]);
	(map->room[n1].curr_link)++;
	map->data = 3;
}

void	ft_valid(t_map *map)
{
	char	*line;

	int fd = open("subject.map", O_RDONLY); //ewfkjoghruirejighqgrh0hrgqie
	while (get_next_line(fd, &line))
	{
		if (map->data == 0 && ft_strchr("0123456789-", line[0]))
			number_of_ants(map, line);
		else if (line[0] != '\0' && line[0] == '#')
		{
			// int fd = 0;
			ft_sharp(map, line, fd); // fwegrrfwedfergethryjhtgrfgeth
		}
		else if (line[0] != '\0' && line[0] != 'L'
			&& (map->data == 3 || ft_strchr(line, '-')))
			the_links(map, line);
		else if (line[0] != '\0' && line[0] != 'L'
			&& (map->data == 1 || map->data == 2))
			the_room(map, line, 2);/* 0 - start, 1 - end, 2 - another */
		else
		{
			free(map);
			free(line);
			write(2, "Error\n", 6);
			exit(0);
		}
		free(line);
	}
	printf("map->start = %d\n", map->start);
	printf("map->end = %d\n", map->end);
	if (map->data != 3 || !map->start || !map->end)
	{
		free(map);
		write(2, "Error\n", 6);
		exit(0);
	}
	close(fd);//defwgrijuhirfeijwhqrugofjpwihrugiofjowghruifwijhu
}

int     main()
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	// int j = 0;
	// while (j < 100000)
	// {
	// 	map->room[j].curr_link = 0;
	// 	j++;
	// }
	ft_valid(map);
	int n = ft_find_hash("2");
	printf("name = %s\n", map->room[n].name);
	printf("curr_link before while = %d\n", map->room[n].curr_link);
	while (map->room[n].curr_link > 0)
	{
		map->room[n].curr_link--;
		printf("curr_link = %d\n", map->room[n].curr_link);
		ft_printf("%s\n", map->room[n].links[map->room[n].curr_link]);
	}
	free(map);
	return (0);
}
