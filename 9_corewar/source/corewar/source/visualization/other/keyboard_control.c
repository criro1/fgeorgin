/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:35:43 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 03:49:49 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	speed_change(t_visu_keyboard *keyboard, int amount)
{
	int	sum;

	sum = keyboard->speed + amount;
	if (sum > 0 && sum <= MAX_SPEED_VISU)
	{
		keyboard->speed = sum;
		keyboard->microseconds = 1000000 / sum;
	}
}

static void	speed_max_or_default(t_visu_keyboard *keyboard, char status)
{
	if (status == 's')
	{
		keyboard->speed = MAX_SPEED_VISU;
		keyboard->microseconds = 1000000 / MAX_SPEED_VISU;
	}
	else if (status == 'd')
	{
		keyboard->speed = DEFAULT_SPEED_VISU;
		keyboard->microseconds = 1000000 / DEFAULT_SPEED_VISU;
	}
}

static void	pressing_keys(t_visu_keyboard *keyboard, int key)
{
	if (key == 'q' || key == 'Q')
		speed_change(keyboard, -10);
	else if (key == 'w' || key == 'W')
		speed_change(keyboard, -1);
	else if (key == 'e' || key == 'E')
		speed_change(keyboard, 1);
	else if (key == 'r' || key == 'R')
		speed_change(keyboard, 10);
	else if (key == 's' || key == 'S')
		speed_max_or_default(keyboard, 's');
	else if (key == 'd' || key == 'D')
		speed_max_or_default(keyboard, 'd');
	else if (key == ' ')
		if (keyboard->pause == True)
			keyboard->pause = False;
		else
			keyboard->pause = True;
	else if (key == 27 && keyboard->pause == False)
		keyboard->exit = True;
}

void		*keyboard_control(void *keyboard_control)
{
	t_visu_keyboard		*keyboard;
	int					key;

	keyboard = keyboard_control;
	while (keyboard->exit == False || keyboard->pause == True)
	{
		key = getch();
		pressing_keys(keyboard, key);
	}
	pthread_exit(EXIT_SUCCESS);
}
