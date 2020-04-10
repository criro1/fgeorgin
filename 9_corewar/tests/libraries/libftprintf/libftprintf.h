/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:08:32 by mwuckert          #+#    #+#             */
/*   Updated: 2020/01/11 20:22:59 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# include "./float/libftfloat.h"

# define BUFF_SIZE 1024
# define FLAGS "-+ #0"
# define TYPES "cspdiouxXfUb"
# define BASE_UPPER "0123456789ABCDEF"
# define BASE_LOWER "0123456789abcdef"
# define WRITE_ZERO(arg) (arg & 136) == 8
# define IS_NEGATIVE_NUM(arg) (arg & 1)
# define IS_SHARP(arg) (arg & 16)
# define IS_SPACE (arg) (arg & 32)
# define IS_PLUS (arg) (arg & 64)
# define IS_SIGN(arg) (arg & 97)
# define IS_MINUS(arg) (arg & 128)
# define PUT_MINUS(arg) (arg |= 128)
# define CAST_I(arg) ((int*) arg)
# define CAST_L(arg) ((long*) arg)
# define CAST_S(arg) ((short*) arg)
# define CAST_U(arg) ((unsigned *) arg)
# define CAST_LL(arg) ((long long*) arg)
# define CAST_TFUNC(arg) ((t_func *) arg)
# define CAST_C(arg) ((signed char*) arg)
# define CAST_UL(arg) ((unsigned long*) arg)
# define CAST_UC(arg) ((unsigned char*) arg)
# define CAST_US(arg) ((unsigned short*) arg)
# define CAST_ULL(arg) ((unsigned long long*) arg)
# define UNDEFINED_BEHAVIOR(arg) *arg == 'j' || *arg == 'z' || *arg == '.'
# define FORMAT_P1(a) a##c, a##s, a##p, a##d, a##d
# define FORMAT_P2(a) a##o, a##u, a##x, a##x, a##f, a##u
# define FORMAT_EXTRA(a) a##b
# define FORMAT(a) FORMAT_P1(a), FORMAT_P2(a), FORMAT_EXTRA(a)
# define ARG(f) f##i, f##c, f##s, f##l, f##ll, f##u, f##uc, f##us, f##ul, f##ull
# define FUNC FORMAT(ft_format_), ft_format_basic, ARG(ft_varg_)

typedef	char		t_ulint[9];

typedef struct		s_buf
{
	char			buf[BUFF_SIZE];
	int				fd_out;
	char			*start;
	char			*end;
}					t_buf;

typedef struct		s_len
{
	int				space;
	int				zero;
	int				num;
	unsigned char	base;
	unsigned char	flags;
}					t_len;

typedef struct		s_format
{
	void			*func;
	int				width;
	int				types;
	int				precision;
	char			*str;
	char			*save;
	unsigned char	size;
	unsigned char	ld_size;
	unsigned char	flags;
	t_len			len;
}					t_format;

typedef struct		s_print
{
	int				displayed;
	va_list			args;
	t_format		format;
	t_ulint			arg;
	t_buf			buf;
}					t_print;

typedef void		(*t_func)(t_print*);
typedef	t_func		t_functions[];

int					ft_dprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
int					ft_format_specifer(t_print *sp);
int					ft_is_specifer(t_print *sp);
void				ft_parse(t_print *sp);
void				ft_format(t_print *sp);
void				ft_varg_c(t_print *sp);
void				ft_varg_i(t_print *sp);
void				ft_varg_s(t_print *sp);
void				ft_varg_l(t_print *sp);
void				ft_varg_u(t_print *sp);
void				ft_varg_us(t_print *sp);
void				ft_varg_ul(t_print *sp);
void				ft_varg_uc(t_print *sp);
void				ft_varg_ll(t_print *sp);
void				ft_varg_ull(t_print *sp);
void				ft_format_c(t_print *sp);
void				ft_format_s(t_print *sp);
void				ft_format_p(t_print *sp);
void				ft_format_d(t_print *sp);
void				ft_format_o(t_print *sp);
void				ft_format_u(t_print *sp);
void				ft_format_x(t_print *sp);
void				ft_format_f(t_print *sp);
void				ft_format_b(t_print *sp);
void				ft_handling(t_print *sp);
void				ft_write_buf(t_print *sp);
void				ft_add_to_buf(t_print *sp);
void				ft_parse_size(t_print *sp);
void				ft_parse_print(t_print *sp);
void				ft_parse_flags(t_print *sp);
void				ft_parse_width(t_print *sp);
void				ft_parse_types(t_print *sp);
void				ft_format_basic(t_print *sp);
void				ft_add_num_to_buf(t_print *sp);
void				ft_add_str_to_buf(t_print *sp);
void				ft_add_strn_to_buf(t_print *sp);
void				ft_calculate_width(t_print *sp);
void				ft_add_zero_to_buf(t_print *sp);
void				ft_add_sign_to_buf(t_print *sp);
void				ft_parse_precision(t_print *sp);
void				ft_add_space_to_buf(t_print *sp);
void				ft_calculate_precision(t_print *sp);
void				ft_add_full_format_to_buf(t_print *sp);
void				ft_skip_undefined_behavior(t_print *sp);
void				ft_add_real_num_to_buf(t_real *num, t_print *p);
t_real				*ft_get_t_real(t_print *sp);

#endif
