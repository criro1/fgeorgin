/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:42:51 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/10/14 21:14:32 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE1 10
# define LIM 9999
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# define BUFF_SIZE 150000
# define S1_SIZE 15000
# define S2_SIZE 15000
# include <stdio.h>
# include <float.h>
# include <limits.h>
# include <math.h>

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
							size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
							char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_min(int *mas, size_t size);
int						ft_max(int *mas, size_t size);
int						ft_sqrt(int x);
int						ft_strnumchr(char *str, char c);
int						get_next_line(const int fd, char **line);

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
							void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

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
