/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprinf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:16:14 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/12 12:08:59 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_print specify;

	if (write(fd, NULL, 0) < 0)
	{
		write(2, "Bad descriptor!\n", 16);
		return (EXIT_FAILURE);
	}
	va_start(specify.args, format);
	specify.format.str = (char*)format;
	specify.buf.start = specify.buf.buf;
	specify.buf.end = specify.buf.start + BUFF_SIZE;
	specify.buf.fd_out = fd;
	specify.displayed = 0;
	ft_handling(&specify);
	ft_write_buf(&specify);
	va_end(specify.args);
	return (specify.displayed);
}
