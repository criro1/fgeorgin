# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 20:59:45 by fgeorgin          #+#    #+#              #
#    Updated: 2019/11/18 17:11:34 by fgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap

CHECKER = checker

HEADER = ./header/push_swap.h

LIBFT = ./libft/libft.a

SRC_PS = ./push_swap_f/push_swap.c ./push_swap_f/screw.c ./push_swap_f/sorting.c \
./push_swap_f/way_func.c ./push_swap_f/find_way.c

SRC_CH= ./checker_f/checker.c

SRC_GEN = ./general/functions.c ./general/make_list.c ./general/operations.c

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

OBJ_GEN = $(SRC_GEN:.c=.o)

all: $(LIBFT) $(OBJ_PS) $(OBJ_CH) $(OBJ_GEN) $(PS) $(CHECKER)

$(LIBFT):
	make -C ./libft

$(OBJ_PS): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(OBJ_CH): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(OBJ_GEN): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(PS): $(OBJ_PS) $(OBJ_GEN) $(HEADER)
	gcc -Wall -Wextra -Werror $(OBJ_PS) $(OBJ_GEN) $(LIBFT) -o $(PS)

$(CHECKER): $(OBJ_CH) $(OBJ_GEN) $(HEADER)
	gcc -Wall -Wextra -Werror $(OBJ_CH) $(OBJ_GEN) $(LIBFT) -o $(CHECKER)

clean:
	/bin/rm -f $(OBJ_PS) $(OBJ_CH) $(OBJ_GEN)
	make clean -C ./libft
	
fclean: clean
	rm -rf $(PS) $(CHECKER)
	make fclean -C ./libft

re: fclean all