# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 20:58:29 by wmaykit           #+#    #+#              #
#    Updated: 2020/04/26 09:29:24 by artem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	ft_printf.c ft_dprintf.c ft_format_specifer.c ft_parse_precision.c \
		ft_format.c ft_format_c.c ft_format_s.c ft_format_p.c ft_format_d.c \
		ft_format_o.c ft_format_u.c ft_format_x.c ft_format_f.c \
		ft_format_b.c ft_parse.c ft_parse_size.c ft_parse_print.c \
		ft_parse_flags.c ft_parse_width.c ft_parse_types.c \
		ft_format_basic.c ft_varg_c.c ft_varg_i.c \
		ft_varg_s.c ft_varg_l.c ft_varg_u.c ft_varg_us.c ft_varg_ul.c \
		ft_varg_uc.c ft_varg_ll.c ft_varg_ull.c ft_add_to_buf.c \
		ft_add_num_to_buf.c ft_add_str_to_buf.c ft_add_zero_to_buf.c \
		ft_add_sign_to_buf.c ft_add_space_to_buf.c ft_add_full_format_to_buf.c \
		ft_add_strn_to_buf.c ft_add_real_num_to_buf.c ft_get_t_real.c \
		ft_calculate_width.c ft_write_buf.c ft_handling.c ft_is_specifer.c \
		ft_skip_undefined_behavior.c ft_calculate_precision.c

SRC_LFT = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
		ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
		ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strtrim.c \
		ft_strsub.c ft_strlenc.c ft_strsplit.c ft_countwordc.c \
		ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c \
		ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
		ft_lstdelcontent.c ft_twodarraydel.c ft_countchar.c \
		ft_swap_point.c ft_swap.c ft_power.c ft_sqrt.c \
		ft_delelemofarray.c ft_atoi_base.c ft_strchri.c \
		ft_base_len.c ft_strnlen.c
 
SRC_FLOAT =	ft_create_treal.c ft_create_tieee754.c \
		ft_addition_num.c ft_conversion_powers.c ft_normalize_num.c \
		ft_parse_float.c ft_parse_double.c ft_parse_power_mantis.c  \
		ft_parse_ldouble.c ft_parse_parts_ieee754.c \
		ft_print_tparts.c ft_print_tpowers.c \
		ft_delete_treal.c ft_delete_tieee754.c \
		ft_get_real_number.c ft_get_integer_part.c ft_get_frac_part.c \
		ft_move_digit.c ft_rounding_treal.c 

SRC_LFTS = $(addprefix $(INCLUDES_LFT),$(SRC_LFT))

SRC_FLOATS = $(addprefix $(INCLUDES_LFTFLOAT),$(SRC_FLOAT))

SRCS += $(SRC_LFTS)

SRCS += $(SRC_FLOATS)

OBJECTS = $(SRCS:.c=.o)

INCLUDES_LFT = ../libft/

INCLUDES_LFTFLOAT = float/

FLAGS = -Wall -Wextra -Werror

all: init_loading $(NAME) destroy_loading

init_loading:
	@../../scripts/make_scripts/init_loading_bar.py "$(OBJECTS)" "$(SRCS)" "$(NAME:.a=.h)" "$(NAME)"

destroy_loading:
	@../../scripts/make_scripts/destroy_loading_bar.py

$(NAME): $(OBJECTS)
	@ar -r -c -s $(NAME) $(OBJECTS)
	@printf "\r\e[2K"
	@echo "Done compilling $(NAME)!"

$(OBJECTS): %.o: %.c $(NAME:.a=.h)
	@gcc $(FLAGS) -c $< -I $(INCLUDES_LFT) -I $(INCLUDES_LFTFLOAT) -o $@
	@../../scripts/make_scripts/print_step_loading.py $<

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re init_loading destroy_loading

