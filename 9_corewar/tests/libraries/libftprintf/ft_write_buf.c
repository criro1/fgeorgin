/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 00:15:42 by mwuckert          #+#    #+#             */
/*   Updated: 2020/01/11 20:21:16 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_write_buf(t_print *sp)
{
	sp->displayed += write(sp->buf.fd_out, sp->buf.buf,
												sp->buf.start - sp->buf.buf);
	sp->buf.start = sp->buf.buf;
}
