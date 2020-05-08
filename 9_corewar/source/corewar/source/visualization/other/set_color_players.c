/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:51:43 by astamm            #+#    #+#             */
/*   Updated: 2020/03/16 16:59:27 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_boolean	check_duplicates(int *arr, int amount)
{
	int	index;
	int repeat;
	int numb;
	int	j;

	index = 0;
	j = 0;
	while (index < amount)
	{
		numb = arr[index++];
		repeat = 0;
		while (j < amount && repeat <= 1)
			if (arr[j++] == numb)
				repeat++;
		j = 0;
		if (repeat >= 2)
			return (True);
	}
	return (False);
}

void				set_color_players(t_visu_gamers *gamers)
{
	int			index;
	int			color[gamers->amount];

	index = 0;
	srand(time(NULL));
	while (index < gamers->amount)
	{
		color[index] = 1 + rand() % (AMOUNT_COLOR_PAIRS - 1);
		while (check_duplicates(color, index + 1) == True)
			color[index] = 1 + rand() % (AMOUNT_COLOR_PAIRS - 1);
		gamers->player[index].color_pair = color[index];
		index++;
	}
}
