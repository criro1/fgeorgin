# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/26 09:22:22 by wmaykit           #+#    #+#              #
#    Updated: 2019/12/17 18:55:53 by wmaykit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftfloat.a

NAME_LFT = $(INCLUDES)libft.a

SRCS =	ft_create_treal.c ft_create_tieee754.c \
		ft_addition_num.c ft_conversion_powers.c ft_normalize_num.c \
		ft_parse_float.c ft_parse_double.c ft_parse_power_mantis.c  \
		ft_parse_ldouble.c ft_parse_parts_ieee754.c \
		ft_print_tparts.c ft_print_tpowers.c \
		ft_delete_treal.c ft_delete_tieee754.c \
		ft_get_real_number.c ft_get_integer_part.c ft_get_frac_part.c \
		ft_move_digit.c ft_rounding_treal.c 


SRCS += $(wildcard $(INCLUDES)*.c)

OBJECTS = $(SRCS:.c=.o)

INCLUDES = ../../libft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -r -c -s $(NAME) $(OBJECTS)
	@echo "Done compilling $(NAME)!"

$(OBJECTS): %.o : %.c $(NAME:.a=.h) 
	@gcc $(FLAGS) -c $< -I $(INCLUDES) -o $@
	
norm:
	norminette $(SRCS) $(NAME:.a=.h) 
	
clean:
	@echo "Object file libftfloat deletion process..."
	@rm -f $(OBJECTS)
	@echo "Object file libftfloat deleted!"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) file deleted!"
	@rm -f $(NAME_LFT)
	@echo "$(NAME_LFT) file deleted!"

re: fclean all

.PHONY: all clean fclean re norm
