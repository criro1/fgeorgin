# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnita <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 17:43:11 by pnita             #+#    #+#              #
#    Updated: 2019/04/07 18:30:46 by pnita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT = sources/libft
DIR_S = sources
DIR_O = temporary
HEADER = include
SOURCES = ft_printf.c do_with_f.c do_with_i.c do_with_o_get_oux.c \
do_with_per_c_s_p.c do_with_ux_and_par_to_beg.c f_get_strings.c \
f_m_and_str_plus.c f_round_f_sign.c f_to_buff_and_images.c ft_printf.c set_par.c
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
all: $(NAME)
$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp sources/libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p temporary
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@
clean:
	rm -rf $(DIR_O)
	rm -f $(OBJS)
	make clean -C $(LIBFT)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
re: fclean all