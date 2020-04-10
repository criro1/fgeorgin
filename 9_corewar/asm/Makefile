# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 13:42:34 by cwitting          #+#    #+#              #
#    Updated: 2020/03/17 10:34:57 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = libft

LIB_FT_A = $(LIB_DIR)/libft.a

SRC_FILES = asm.c assemble.c ft_strnjoin.c create_token.c get_name.c get_comment.c \
			check_symb_after_quot_mark.c check_size.c check_for_incorr_symb_before.c \
			check_line_beginning.c parse_after_label.c begin_is_instruction.c \
			parse_args.c label_char_correct.c parser.c ft_exit.c to_byte_code.c \
			check_for_incorr_symb_after.c clean.c right_number_of_args_1.c \
			right_number_of_args_2.c right_number_of_args_3.c ft_strnjoin_free.c \
			ft_strjoin_free.c ft_strncat_free.c check_valid_token.c write_part_1.c \
			write_args_types_code_fd.c write_instruction_code_fd.c write_name_com.c \
			byte_code_utils.c assign_value_to_label.c write_direct_fd.c \
			write_dir_label_fd.c arg_amount.c create_arg.c func_in_parse_args.c \
			parse_args_utils.c name_comment_is_correct.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror -g

all: libft $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(INC_DIR)/asm.h $(LIB_FT_A)
	gcc $(FLAGS) $(OBJS) -I $(INC_DIR) -L $(LIB_DIR) -lft -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)/asm.h
	gcc $(FLAGS) -c $< -I $(LIB_DIR) -I $(INC_DIR) -o $@

$(LIB_FT_A): libft

libft:
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean:
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re:	fclean all

.PHONY: all libft clean fclean re