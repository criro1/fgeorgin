# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgin <fgeorgin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/05 13:42:34 by fgeorgin          #+#    #+#              #
#    Updated: 2020/04/25 20:58:34 by artem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM		= asm
NAME_VM			= corewar

SCRIPT_DIR		= ./scripts/make_scripts

ASM_DIR			= source/asm
ASM_FULL_PATH	= $(addprefix $(ASM_DIR)/,$(NAME_ASM))

VM_DIR			= source/corewar
VM_FULL_PATH	= $(addprefix $(VM_DIR)/,$(NAME_VM))

all: $(NAME_ASM) $(NAME_VM)

$(NAME_ASM): $(ASM_FULL_PATH)

$(ASM_FULL_PATH): make_asm
	@$(SCRIPT_DIR)/move_bin.py "$(ASM_FULL_PATH)" "$(NAME_ASM)"

make_asm:
	@make -C $(ASM_DIR)

$(NAME_VM): $(VM_FULL_PATH)

$(VM_FULL_PATH): make_vm
	@$(SCRIPT_DIR)/move_bin.py "$(VM_FULL_PATH)" "$(NAME_VM)"

make_vm:
	@make -C $(VM_DIR)

clean:
	@make clean -C $(ASM_DIR)
	@make clean -C $(VM_DIR)

fclean:
	@make fclean -C $(ASM_DIR)
	@make fclean -C $(VM_DIR)
	@rm -f $(NAME_ASM) $(NAME_VM)

re:	fclean all

.PHONY: all clean fclean re make_asm make_vm
