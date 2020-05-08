# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astamm <astamm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 15:15:48 by mwuckert          #+#    #+#              #
#    Updated: 2020/04/26 09:27:57 by artem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
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
		ft_base_len.c get_next_line.c ft_quick_sort.c ft_isspace.c ft_strnlen.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: fclean all re print_comp

all: init_loading $(NAME) destroy_loading

init_loading:
	@../../scripts/make_scripts/init_loading_bar.py "$(OBJECTS)" "$(SRC)" "libft.h" "$(NAME)"

destroy_loading:
	@../../scripts/make_scripts/destroy_loading_bar.py

$(NAME): $(OBJECTS) libft.h
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "\r\e[2K"
	@echo "Done compilling $(NAME)!"

%.o : %.c 
	@gcc $(FLAGS) -c $< -I.
	@../../scripts/make_scripts/print_step_loading.py $<

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -fr $(NAME)

re: fclean all init_loading destroy_loading

