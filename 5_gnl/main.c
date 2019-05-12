/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:03:41 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/12 13:04:56 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	int i = 0;
	while (get_next_line(fd, &line))
	{
		//i++;
		//printf("ret = %d\n", get_next_line(fd, &line));
		printf("line = %s\n", line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
