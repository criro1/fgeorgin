/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:10:20 by mwuckert          #+#    #+#             */
/*   Updated: 2020/01/12 12:24:59 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	t_print specify;

	va_start(specify.args, format);
	specify.format.str = (char*)format;
	specify.buf.start = specify.buf.buf;
	specify.buf.end = specify.buf.start + BUFF_SIZE;
	specify.buf.fd_out = STDOUT_FILENO;
	specify.displayed = 0;
	ft_handling(&specify);
	ft_write_buf(&specify);
	va_end(specify.args);
	return (specify.displayed);
}
