# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 13:42:34 by cwitting          #+#    #+#              #
#    Updated: 2020/05/01 17:45:25 by artem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = ../../libraries/libft
LIBPRINT_DIR = ../../libraries/libftprintf

PATH_SCRIPTS = ../../scripts/make_scripts

LIB_FT_A = $(LIB_DIR)/libft.a
LIB_FT_B = $(LIBPRINT_DIR)/libftprintf.a

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

FLAGS = -Wall -Wextra -Werror

all: libft libftprintf init_loading $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(INC_DIR)/asm.h $(LIB_FT_A) $(LIB_FT_B)
	@gcc $(FLAGS) $(OBJS) -L $(LIB_DIR) -lft -L $(LIBPRINT_DIR) -lftprintf -o $@
	@printf "\r\e[2K"
	@echo "Done compilling $(NAME)!"
	@$(PATH_SCRIPTS)/destroy_loading_bar.py

init_loading:
	@$(PATH_SCRIPTS)/init_loading_bar.py "$(OBJS)" "$(SRCS)" "$(INC_DIR)/asm.h" "$(NAME)"

destroy_loading:
	@$(PATH_SCRIPTS)/destroy_loading_bar.py

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)/asm.h
	@$(PATH_SCRIPTS)/print_step_loading.py $(<F)
	@gcc $(FLAGS) -c $< -I $(LIBPRINT_DIR) -I $(LIB_DIR) -I $(INC_DIR) -o $@

$(LIB_FT_A): libft

$(LIB_FT_B): libftprintf

libft:
	@make -C $(LIB_DIR)

libftprintf:
	@make -C $(LIBPRINT_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@make clean -C $(LIBPRINT_DIR)
	@rm -rf $(OBJ_DIR)

fclean:
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(LIBPRINT_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all fclean fclean re libft libftprint init_loading destroy_loading 
