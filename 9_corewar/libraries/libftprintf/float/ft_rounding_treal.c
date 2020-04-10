/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding_treal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:48:53 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/13 22:39:19 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

static void	ft_set_params(t_real *num, t_round *rn, int precision)
{
	rn->len_before = num->frac_position;
	rn->num_roudigit = (num->len_frac - precision);
	rn->num_check = (num->len_frac - precision) - 1;
	rn->round_cell = rn->num_roudigit / 8;
	rn->check_cell = rn->num_check / 8;
	rn->rdigit_in_num = rn->num_roudigit % 8;
	rn->cdigit_in_num = rn->num_check % 8;
	rn->res_num = *(num->fractional + rn->round_cell);
	rn->check_num = *(num->fractional + rn->check_cell);
}

static int	ft_numlen(unsigned num, unsigned *d)
{
	unsigned	*start;

	start = d;
	while (num >= *start)
		++start;
	return (start - d);
}

static void	ft_round_frac_condition(t_real *num, t_round *rn, int precision)
{
	ft_set_params(num, rn, precision);
	if (rn->check_num / rn->d[rn->cdigit_in_num] % 10 >= 5)
		if ((*(num->fractional + rn->round_cell) =
					rn->res_num + rn->d[rn->rdigit_in_num]) >= rn->d[8])
			ft_normalize_num(num->fractional, &num->frac_position);
	*rn->d = 0;
	if (rn->zero_after <= 0 && (rn->len_before != num->frac_position
				|| rn->sign_digit !=
			ft_numlen(num->fractional[num->frac_position], rn->d)))
	{
		if ((*(num->integer) += 1) >= rn->d[8])
			ft_normalize_num(num->integer, &num->len_int);
		num->fractional[num->frac_position] = 0;
		while (!num->fractional[num->frac_position] && num->frac_position)
			--num->frac_position;
	}
	if (num->fractional[num->frac_position + 1])
		++num->frac_position;
}

void		ft_rounding_treal(t_real *num, int precision)
{
	t_round rn;

	rn.d = (unsigned[]){DIGITS};
	rn.sign_digit = ft_numlen(num->fractional[num->frac_position], rn.d);
	rn.zero_after = num->len_frac - (rn.sign_digit + num->frac_position * 8);
	*rn.d = 1;
	if (precision == 0 && rn.zero_after < 1)
	{
		if (*(num->fractional + num->frac_position) /
				rn.d[rn.sign_digit - 1] >= 5)
			if ((*(num->integer) += 1) >= rn.d[8])
				ft_normalize_num(num->integer, &num->len_int);
	}
	else if (precision > 0
			&& precision >= rn.zero_after && precision < num->len_frac)
		ft_round_frac_condition(num, &rn, precision);
}
