/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 21:41:52 by pnita             #+#    #+#             */
/*   Updated: 2019/07/17 21:41:53 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../sources/libft/libft.h"
# define BUFF_SIZE 150000
# define S1_SIZE 15000
# define S2_SIZE 15000

# include <stdio.h>
# include <float.h>
# include <limits.h>
# include <math.h>

typedef	struct			s_par
{
	char				minus;
	char				plus;
	char				space;
	char				zero;
	char				hash;
	int					width;
	int					pre;
	char				*length;
	char				type;
	char				*s1;
	char				*s2;
	char				*m;
}						t_par;

typedef union			u_ld
{
	long double			n;
	struct				s_ld
	{
		unsigned long	m:64;
		unsigned int	e:15;
		unsigned int	s:1;
	}					t_ma;
}						t_ld;

char					g_buff[BUFF_SIZE + 1];
size_t					g_size;

void					par_to_begin(t_par *par);
int						ft_atoi_here(char **str);
void					join_to_buff(char *s, int s_len, char c);
void					join_num_of_c_to_buff(char c, int num);
void					do_with_percent(t_par par);
void					do_with_c(va_list arg, t_par par);
void					do_with_s(va_list arg, t_par par);
char					*itos_with_base(intmax_t n, int base);
char					*uitos_with_base(uintmax_t n, int base, char flag_big);
void					do_with_p_part_2(t_par par, char *s, int *len);
void					do_with_p(va_list arg, t_par par);
intmax_t				get_value_of_i(va_list arg, t_par par);
char					set_i_sign(intmax_t i, t_par par);
void					do_with_i_part_2(t_par par, char sign,
							char *s, int *len);
void					do_with_i(va_list arg, t_par par);
uintmax_t				get_value_of_oux(va_list arg, t_par par);
void					do_with_o_part_2(t_par par, uintmax_t o,
							char *s, int *len);
void					do_with_o(va_list arg, t_par par);
void					do_with_x_part_2(t_par par, char *hash,
							char *s, int *len);
void					do_with_x(va_list arg, t_par par);
void					do_with_u_part_2(t_par par, uintmax_t u,
							char *s, int *len);
void					do_with_u(va_list arg, t_par par);
char					*create_str2(long int n);
void					ft_reverse_str(char *s);
void					put_m_to_str(t_par par, unsigned long m);
void					str1_plus_str_num(char *s, char *str_num);
void					str2_plus_str_num(char *s, char *str_num, int size);
void					plus_n_of_s_to_s(char *s, int n);
void					s_to_pow_with_base_n(char *s, int pow, int *count_sz);
void					len_of_s_b_zero(char *s);
void					get_strings_lf_part_3(char *s_num, int e, t_par par);
void					get_strings_lf_part_2(char *s_num, int e, t_par par);
void					get_strings_lf(t_ld ld, t_par par);
void					round_s1(char *s1);
void					f_round_part_3(t_par par);
void					f_round_part_2(t_par par);
void					f_round(t_par par);
void					f_num_to_buff(t_par par);
void					ft_to_buff_part_2(t_par par, char sign, int len);
void					f_to_buff(t_par par, char sign);
char					set_f_sign(t_ld ld, t_par par);
void					nan_inf_to_buff(char *s, t_par par, char sign);
void					do_with_f_part_2(t_par par, t_ld ld);
void					do_with_f(va_list arg, t_par par);
void					tank_to_buff(void);
void					animal_to_buff(void);
void					welcome_to_buff(void);
void					do_with_par(va_list arg, t_par par);
void					set_length(char **s, char *s_end, t_par *par);
void					set_width_pre_part_2(char **ptr,
							va_list arg, t_par *par);
void					set_width_pre(char **s, char *s_end,
							va_list arg, t_par *par);
void					set_flags(char **s, char *s_end, t_par *par);
void					get_par(char **str, va_list arg);
int						ft_printf(char *format, ...);

#endif
