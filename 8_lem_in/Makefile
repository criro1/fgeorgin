# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ediego <ediego@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 20:59:45 by fgeorgin          #+#    #+#              #
#    Updated: 2020/03/08 17:55:42 by ediego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

NAME_V = visual

HEADER = lem_in.h

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_ants_to_ways.c ft_bfs.c ft_del_links.c ft_exit_func.c ft_finish_sol.c \
ft_free_and_malloc.c ft_if_cross.c ft_move_sh_w.c ft_record_way.c ft_solution_1.c \
ft_suurballe_1.c ft_suurballe.c main.c valid_1.c valid_2.c validation.c \


SRC_V = v/vs_valid_1.c v/vs_valid_2.c v/vs_exit_func.c v/vs_visual.c v/vs_scene.c \
v/vs_scene2.c v/vs_scene3.c v/vs_scene4.c v/vs_key.c v/vs_read_input.c

OBJ = $(SRC:.c=.o)

OBJ_V = $(SRC_V:.c=.o)

all: $(NAME) $(NAME_V)

$(LIBFT):
	@make -C ./libft

$(OBJ): %.o : %.c
	@gcc $(FLAGS) -c $< -o $@

$(OBJ_V): %.o : ./%.c
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	@echo "\033[32mCompiling ./lem-in\033[0m"
	@gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_V): $(LIBFT) $(OBJ_V)
	@echo "\033[32mCompiling ./visual\033[0m"
	@gcc $(FLAGS) $(LIBFT) $(OBJ_V) -o $(NAME_V) -lmlx -framework OpenGL -framework Appkit

	
clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ_V)
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_V)
	@make fclean -C ./libft

re: fclean all
