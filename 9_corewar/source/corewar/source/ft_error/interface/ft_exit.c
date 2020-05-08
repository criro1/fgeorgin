/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:19:59 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/15 17:12:29 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define SEPARATOR	": "

void	ft_exit(char *error_masssage)
{
	char	buff[BUFF_SIZE_EXIT + 1];
	char	*curr;
	int		size_massage;

	if (errno)
	{
		size_massage = ft_strlen(PROGRAMM_NAME) + ft_strlen(SEPARATOR);
		if (size_massage <= BUFF_SIZE_EXIT)
		{
			ft_bzero(buff, BUFF_SIZE_EXIT + 1);
			curr = ft_strcat(buff, PROGRAMM_NAME);
			if (error_masssage)
			{
				curr = ft_strcat(curr, SEPARATOR);
				ft_strlcat(curr, error_masssage, BUFF_SIZE_EXIT - size_massage);
			}
			perror(buff);
		}
		else
			perror(PROGRAMM_NAME);
		print_usage();
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
