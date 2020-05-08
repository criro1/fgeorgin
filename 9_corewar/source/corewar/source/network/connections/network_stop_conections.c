/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_stop_conections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:24:46 by wmaykit           #+#    #+#             */
/*   Updated: 2020/03/17 01:25:28 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <termios.h>
#include <sys/select.h>

static inline t_boolean	press_key(fd_set *m_rfds, struct timeval *m_tv)
{
	int				ret;

	FD_SET(0, m_rfds);
	ret = select(1, m_rfds, NULL, NULL, m_tv);
	if (ret == -1)
		perror("get key select");
	else if (ret)
		return (True);
	return (False);
}

static inline void		set_params_select(fd_set *m_rfds, struct timeval *m_tv)
{
	FD_ZERO(m_rfds);
	m_tv->tv_sec = 1;
	m_tv->tv_usec = 0;
}

static inline void		set_params_terminal(struct termios *m_tty)
{
	fflush(stdout);
	tcgetattr(0, &(m_tty[0]));
	m_tty[1] = m_tty[0];
	(m_tty[0]).c_lflag &= ~(ISIG | ICANON | ECHO);
	(m_tty[0]).c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &(m_tty[0]));
}

static inline void		reset_params_terminal(struct termios *m_tty)
{
	tcsetattr(0, TCSANOW, &(m_tty[1]));
}

void					*network_stop_conections(void *m_data)
{
	t_connect			*connections;
	t_boolean			*connect;
	struct termios		tty[2];
	fd_set				rfds;
	struct timeval		tv;

	connections = m_data;
	connect = &connections->connect;
	sleep(1);
	set_params_terminal(tty);
	set_params_select(&rfds, &tv);
	while (*connect)
	{
		if (press_key(&rfds, &tv) ||
				connections->connect_players >= connections->max_players)
		{
			usleep(200000);
			*connect = False;
			pthread_cancel(connections->thread[0]);
			break ;
		}
	}
	reset_params_terminal(tty);
	pthread_exit(0);
}
