/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_to_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:02:50 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 18:02:51 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f_num_to_buff(t_par par)
{
	ft_reverse_str(par.s1);
	join_to_buff(par.s1, -1, 0);
	if (par.pre || par.hash)
		join_to_buff(NULL, 0, '.');
	join_to_buff(par.s2, par.pre == -1 ? 6 : par.pre, 0);
}

void		ft_to_buff_part_2(t_par par, char sign, int len)
{
	join_num_of_c_to_buff(' ', par.width - (sign ? 1 : 0) - len);
	if (sign)
		join_to_buff(NULL, 0, sign);
	f_num_to_buff(par);
}

void		f_to_buff(t_par par, char sign)
{
	int		len;

	f_round(par);
	len = ft_strlen(par.s1) + (!par.hash && !par.pre ? 0 : 1)
		+ (par.pre == -1 ? 6 : par.pre);
	if (par.minus)
	{
		if (sign)
			join_to_buff(NULL, 0, sign);
		f_num_to_buff(par);
		join_num_of_c_to_buff(' ', par.width - (sign ? 1 : 0) - len);
	}
	else if (par.zero)
	{
		if (sign)
			join_to_buff(NULL, 0, sign);
		join_num_of_c_to_buff('0', par.width - (sign ? 1 : 0) - len);
		f_num_to_buff(par);
	}
	else
		ft_to_buff_part_2(par, sign, len);
}

void		animal_to_buff(void)
{
	char	*animal;

	animal = "................../~\\/~\\/~\\/~\\/))................\n"
		"................((/~\\/~\\/~\\/~\\/\\))...............\n"
		"..............(/~\\/~\\/~\\/~\\/~/~\\)................\n"
		".............(////......~...~...\\\\\\\\\\)...........\n"
		"...........(\\\\\\\\(...(0)...(0)...)////)...........\n"
		"...........(\\\\\\\\(......_v_......)////)...........\n"
		"............(\\\\\\(.......^........)///)..........\n"
		".................(\\/~\\/~V~V~\\/~\\/................\n"
		"...................(\\/ \\/~\\/ \\/)................\n"
		".....................|...¦ ...|...............\n"
		"..................../|..|.|..|\\...............\n"
		"................._/..|..|.|..|.\\_...._____//...\n"
		"..............(,,)..(,,)_(,,)...(,,)--------..";
	join_to_buff(animal, -1, 0);
}

void		welcome_to_buff(void)
{
	char	*welcome;

	welcome = "●▬▬▬▬▬▬ஜ۩۞۩ஜ۩۞۩ஜ۩۞۩ஜ▬▬▬▬▬▬●\n"
		"┏┓┏┓┏┓╋╋┏┓╋╋╋╋╋╋╋╋╋╋╋╋┏┓\n"
		"┃┃┃┃┃┃╋╋┃┃╋╋╋╋╋╋╋╋╋╋╋╋┃┃\n"
		"┃┃┃┃┃┣━━┫┃┏━━┳━━┳┓┏┳━━┫┃\n"
		"┃┗┛┗┛┃┃━┫┃┃┏━┫┏┓┃┗┛┃┃━╋┛\n"
		"┗┓┏┓┏┫┃━┫┗┫┗━┫┗┛┃┃┃┃┃━╋┓\n"
		"╋┗┛┗┛┗━━┻━┻━━┻━━┻┻┻┻━━┻┛\n"
		"●▬▬▬▬▬▬ஜ۩۞۩ஜ۩۞۩ஜ۩۞۩ஜ▬▬▬▬▬▬●";
	join_to_buff(welcome, -1, 0);
}
