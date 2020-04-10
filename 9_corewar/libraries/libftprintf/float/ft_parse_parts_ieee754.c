/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_parts_ieee754.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:15:29 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/03 21:39:28 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"

void	ft_parse_parts_ieee754(t_ieee754 *st, t_parts *r)
{
	t_func_float *parse_t;

	parse_t = (t_func_float[]){PARSE_FUNC};
	parse_t[st->type](st, r);
}
