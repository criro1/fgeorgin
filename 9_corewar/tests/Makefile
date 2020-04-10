#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 11:38:51 by wmaykit           #+#    #+#              #
#    Updated: 2020/02/03 20:01:12 by wmaykit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= corewar


PATH_OBJS			= ./objects
PATH_LIBFT			= ./libraries/libft
PATH_LIBFT_PRINTF	= ./libraries/libftprintf
PATH_SCRIPTS		= ./scripts/make_scripts
PATH_HEDES			= ./include
PATH_SRCS			= ./source/corewar

HEADER_COREWAR		= $(PATH_HEDES)/corewar.h
HEADER_OP			= $(PATH_HEDES)/op.h
HEADERS_COREWAR		= $(HEADER_COREWAR) $(HEADER_OP)

LIBFT				= $(PATH_LIBFT)/libft.a
LIBFTPRINTF			= $(PATH_LIBFT_PRINTF)/libftprintf.a

################################################################################
#							FT_error										   #
################################################################################
DIR_ERR					= ft_error

DIR_INTERFACE_ERR		= interface

SRCS_INTERFACE_ERR		= save_error_to_log.c ft_exit.c

SRCS_ERR	= $(addprefix $(DIR_INTERFACE_ERR)/, $(SRCS_INTERFACE_ERR)) 
################################################################################

################################################################################
#							NUMBER											   #
################################################################################
DIR_NB					= number

DIR_INTERFACE_NB		= interface

SRCS_INTERFACE_NB		= is_overflow.c is_number.c number_reverse_mem.c

SRCS_NB		= $(addprefix $(DIR_INTERFACE_NB)/, $(SRCS_INTERFACE_NB)) 
################################################################################

################################################################################
#							FILE											   #
################################################################################
DIR_FL					= file

DIR_DEBUG_FL			= debug
DIR_GETSET_FL			= get_set
DIR_INTERFACE_FL		= interface
DIR_CONSTRDESTR_FL		= constr_and_destr

SRCS_DEBUG_FL			= debug_print_file.c
SRCS_GETSET_FL			= file_get_path.c file_get_entry.c file_get_size.c
SRCS_INTERFACE_FL		= file_close.c file_open.c load_file.c file_has_entry.c
SRCS_CONSTRDESTR_FL		= new_file.c destroy_file.c

SRCS_FL		= $(addprefix $(DIR_DEBUG_FL)/, $(SRCS_DEBUG_FL)) \
			  $(addprefix $(DIR_GETSET_FL)/, $(SRCS_GETSET_FL)) \
			  $(addprefix $(DIR_INTERFACE_FL)/, $(SRCS_INTERFACE_FL)) \
			  $(addprefix $(DIR_CONSTRDESTR_FL)/, $(SRCS_CONSTRDESTR_FL))
################################################################################

################################################################################
#							ARGUMENTS										   #
################################################################################
DIR_ARG					= arguments

DIR_DEBUG_ARG			= debug
DIR_PARSING_ARG			= parsing
DIR_INTERFACE_ARG		= interface
DIR_VALIDATIONS_ARG		= validations
DIR_CONSTRDESTR_ARG		= constr_and_destr

SRCS_DEBUG_ARG			= debug_print_args_obj.c
SRCS_PARSING_ARG		= add_new_options_to_arg_obj.c \
						  add_file_new_player_to_arg_obj.c
SRCS_INTERFACE_ARG		= get_option_obj.c pop_players.c pop_options.c
SRCS_VALIDATIONS_ARG	= new_valid_obj.c \
						  \
						  valid_visual.c valid_dump.c valid_n.c \
						  \
						  validation_args.c
SRCS_CONSTRDESTR_ARG	= destroy_args_obj.c new_args_obj.c

SRCS_ARG	= $(addprefix $(DIR_DEBUG_ARG)/, $(SRCS_DEBUG_ARG)) \
			  $(addprefix $(DIR_PARSING_ARG)/, $(SRCS_PARSING_ARG)) \
			  $(addprefix $(DIR_INTERFACE_ARG)/, $(SRCS_INTERFACE_ARG)) \
			  $(addprefix $(DIR_VALIDATIONS_ARG)/, $(SRCS_VALIDATIONS_ARG)) \
			  $(addprefix $(DIR_CONSTRDESTR_ARG)/, $(SRCS_CONSTRDESTR_ARG))
################################################################################

################################################################################
#							OPTIONS											   #
################################################################################
DIR_OPT					= options

DIR_INTERFACE_OPT		= interface
DIR_CONSTRDESTR_OPT		= constr_and_destr

SRCS_INTERFACE_OPT		= get_id_options.c is_options.c is_options_player.c \
						  add_option.c 
SRCS_CONSTRDESTR_OPT	= destroy_options.c new_obj_dump.c \
						  destroy_options_list.c new_options_list.c

SRCS_OPT	= $(addprefix $(DIR_INTERFACE_OPT)/, $(SRCS_INTERFACE_OPT)) \
			  $(addprefix $(DIR_CONSTRDESTR_OPT)/, $(SRCS_CONSTRDESTR_OPT))
################################################################################

################################################################################
#							PLAYER											   #
################################################################################
DIR_PL					= player

DIR_DEBUG_PL			= debug
DIR_GETSET_PL			= get_set
DIR_PARSING_PL			= parsing
DIR_INTERFACE_PL		= interface
DIR_VALIDATIONS_PL		= validations
DIR_CONSTRDESTR_PL		= constr_and_destr

SRCS_DEBUG_PL			= debug_print_player.c
SRCS_GETSET_PL			= player_get_size.c
SRCS_PARSING_PL			= player_parsing.c 
SRCS_INTERFACE_PL		= player_memcpy.c
SRCS_VALIDATIONS_PL		= player_validation.c
SRCS_CONSTRDESTR_PL		= destroy_player.c new_player.c init_player.c

SRCS_PL		= $(addprefix $(DIR_DEBUG_PL)/, $(SRCS_DEBUG_PL)) \
			  $(addprefix $(DIR_GETSET_PL)/, $(SRCS_GETSET_PL)) \
			  $(addprefix $(DIR_PARSING_PL)/, $(SRCS_PARSING_PL)) \
			  $(addprefix $(DIR_INTERFACE_PL)/, $(SRCS_INTERFACE_PL)) \
			  $(addprefix $(DIR_VALIDATIONS_PL)/, $(SRCS_VALIDATIONS_PL)) \
			  $(addprefix $(DIR_CONSTRDESTR_PL)/, $(SRCS_CONSTRDESTR_PL))
################################################################################

################################################################################
#							PLAYERS											   #
################################################################################
DIR_PLS					= players

DIR_DEBUG_PLS			= debug
DIR_GETSET_PLS			= get_set
DIR_INTERFACE_PLS		= interface
DIR_CONSTRDESTR_PLS		= constr_and_destr

SRCS_DEBUG_PLS			= debug_print_players.c
SRCS_GETSET_PLS			= players_get_amount.c players_get_player.c
SRCS_INTERFACE_PLS		= push_player_to_players.c add_to_players.c \
						  players_memcpy.c
SRCS_CONSTRDESTR_PLS	= destroy_players.c new_players.c init_players.c

SRCS_PLS	= $(addprefix $(DIR_DEBUG_PLS)/, $(SRCS_DEBUG_PLS)) \
			  $(addprefix $(DIR_GETSET_PLS)/, $(SRCS_GETSET_PLS)) \
			  $(addprefix $(DIR_INTERFACE_PLS)/, $(SRCS_INTERFACE_PLS)) \
			  $(addprefix $(DIR_CONSTRDESTR_PLS)/, $(SRCS_CONSTRDESTR_PLS))
################################################################################

################################################################################
#							PRINT											   #
################################################################################
DIR_PR					= print

DIR_INTERFACE_PR		= interface

SRCS_INTERFACE_PR		= print_line.c print_space.c print_memory.c

SRCS_PR	= $(addprefix $(DIR_INTERFACE_PR)/, $(SRCS_INTERFACE_PR)) 
################################################################################

################################################################################
#							MEMORY											   #
################################################################################
DIR_MR					= memory

DIR_DEBUG_MR			= debug
DIR_GETSET_MR			= get_set
DIR_INTERFACE_MR		= interface
DIR_CONSTRDESTR_MR		= constr_and_destr

SRCS_DEBUG_MR			= 
SRCS_GETSET_MR			= memory_get_size.c memory_get_amount_segments.c \
						  memory_get_address_segment.c
SRCS_INTERFACE_MR		= mamory_export_dump.c memory_read.c
SRCS_CONSTRDESTR_MR		= new_memory.c

SRCS_MR		= $(addprefix $(DIR_DEBUG_MR)/, $(SRCS_DEBUG_MR)) \
			  $(addprefix $(DIR_GETSET_MR)/, $(SRCS_GETSET_MR)) \
			  $(addprefix $(DIR_INTERFACE_MR)/, $(SRCS_INTERFACE_MR)) \
			  $(addprefix $(DIR_CONSTRDESTR_MR)/, $(SRCS_CONSTRDESTR_MR))
################################################################################

################################################################################
#							PARAMS											   #
################################################################################
DIR_PAR					= params

DIR_DEBUG_PAR			= debug
DIR_GETSET_PAR			= get_set
DIR_PARSING_PAR			= parsing
DIR_INTERFACE_PAR		= interface
DIR_VALIDATIONS_PAR		= validations
DIR_CONSTRDESTR_PAR		= constr_and_destr

SRCS_DEBUG_PAR			= 
SRCS_GETSET_PAR			= 
SRCS_PARSING_PAR		= 
SRCS_INTERFACE_PAR		= 
SRCS_VALIDATIONS_PAR	= 
SRCS_CONSTRDESTR_PAR	= new_params.c

SRCS_PAR	= $(addprefix $(DIR_DEBUG_PAR)/, $(SRCS_DEBUG_PAR)) \
			  $(addprefix $(DIR_GETSET_PAR)/, $(SRCS_GETSET_PAR)) \
			  $(addprefix $(DIR_PARSING_PAR)/, $(SRCS_PARSING_PAR)) \
			  $(addprefix $(DIR_INTERFACE_PAR)/, $(SRCS_INTERFACE_PAR)) \
			  $(addprefix $(DIR_VALIDATIONS_PAR)/, $(SRCS_VALIDATIONS_PAR)) \
			  $(addprefix $(DIR_CONSTRDESTR_PAR)/, $(SRCS_CONSTRDESTR_PAR))
################################################################################

################################################################################
#							CARRIAGE										   #
################################################################################
DIR_CAR					= carriage

DIR_DEBUG_CAR			= debug
DIR_GETSET_CAR			= get_set
DIR_PARSING_CAR			= parsing
DIR_INTERFACE_CAR		= interface
DIR_VALIDATIONS_CAR		= validations
DIR_CONSTRDESTR_CAR		= constr_and_destr

SRCS_DEBUG_CAR			= 
SRCS_GETSET_CAR			= carriage_set_id.c carriage_set_oper_code.c
SRCS_PARSING_CAR		= 
SRCS_INTERFACE_CAR		= carriage_need_set_code.c
SRCS_VALIDATIONS_CAR	= 
SRCS_CONSTRDESTR_CAR	= new_carriage.c destroy_carriage.c

SRCS_CAR	= $(addprefix $(DIR_DEBUG_CAR)/, $(SRCS_DEBUG_CAR)) \
			  $(addprefix $(DIR_GETSET_CAR)/, $(SRCS_GETSET_CAR)) \
			  $(addprefix $(DIR_PARSING_CAR)/, $(SRCS_PARSING_CAR)) \
			  $(addprefix $(DIR_INTERFACE_CAR)/, $(SRCS_INTERFACE_CAR)) \
			  $(addprefix $(DIR_VALIDATIONS_CAR)/, $(SRCS_VALIDATIONS_CAR)) \
			  $(addprefix $(DIR_CONSTRDESTR_CAR)/, $(SRCS_CONSTRDESTR_CAR))
################################################################################

################################################################################
#							CARRIAGES										   #
################################################################################
DIR_CARS				= carriages

DIR_DEBUG_CARS			= debug
DIR_GETSET_CARS			= get_set
DIR_PARSING_CARS		= parsing
DIR_INTERFACE_CARS		= interface
DIR_VALIDATIONS_CARS	= validations
DIR_CONSTRDESTR_CARS	= constr_and_destr

SRCS_DEBUG_CARS			= 
SRCS_GETSET_CARS		= 
SRCS_PARSING_CARS		= 
SRCS_INTERFACE_CARS		= carriages_add_carige.c carriages_iterator_set_next.c 
SRCS_VALIDATIONS_CARS	= 
SRCS_CONSTRDESTR_CARS	= new_carriages.c destroy_carriages.c \
						  carriages_init_iterator.c

SRCS_CARS	= $(addprefix $(DIR_DEBUG_CARS)/, $(SRCS_DEBUG_CARS)) \
			  $(addprefix $(DIR_GETSET_CARS)/, $(SRCS_GETSET_CARS)) \
			  $(addprefix $(DIR_PARSING_CARS)/, $(SRCS_PARSING_CARS)) \
			  $(addprefix $(DIR_INTERFACE_CARS)/, $(SRCS_INTERFACE_CARS)) \
			  $(addprefix $(DIR_VALIDATIONS_CARS)/, $(SRCS_VALIDATIONS_CARS)) \
			  $(addprefix $(DIR_CONSTRDESTR_CARS)/, $(SRCS_CONSTRDESTR_CARS))
################################################################################

################################################################################
#							COREWAR											   #
################################################################################
DIR_CR					= corewar

DIR_INTERFACE_CR		= interface
DIR_CONSTRDESTR_CR		= constr_and_destr

SRCS_INTERFACE_CR		= print_usage.c corewar.c is_suitable_file.c
SRCS_CONSTRDESTR_CR		= new_corewar.c

SRCS_CR		= $(addprefix $(DIR_INTERFACE_CR)/, $(SRCS_INTERFACE_CR)) \
			  $(addprefix $(DIR_CONSTRDESTR_CR)/, $(SRCS_CONSTRDESTR_CR))
################################################################################

SRCS_DEMO	= $(addprefix $(DIR_ARG)/,$(SRCS_ARG))	\
			  $(addprefix $(DIR_PL)/,$(SRCS_PL))	\
			  $(addprefix $(DIR_PLS)/,$(SRCS_PLS))	\
			  $(addprefix $(DIR_PR)/,$(SRCS_PR))	\
			  $(addprefix $(DIR_OPT)/,$(SRCS_OPT))	\
			  $(addprefix $(DIR_FL)/,$(SRCS_FL))	\
			  $(addprefix $(DIR_NB)/,$(SRCS_NB))	\
			  $(addprefix $(DIR_MR)/,$(SRCS_MR))	\
			  $(addprefix $(DIR_PAR)/,$(SRCS_PAR))	\
			  $(addprefix $(DIR_CAR)/,$(SRCS_CAR))	\
			  $(addprefix $(DIR_CARS)/,$(SRCS_CARS))\
			  $(addprefix $(DIR_CR)/,$(SRCS_CR))	\
			  $(addprefix $(DIR_ERR)/,$(SRCS_ERR))

SRCS_WITH_PATH		= $(SRCS_DEMO) main.c

SRCS_WITH_FULL_PATH = $(addprefix ./source/,$(SRCS_WITH_PATH))

OBJS				= $(SRCS_WITH_PATH:.c=.o)

OBJS_WITH_PATH		= $(addprefix $(PATH_OBJS)/,$(OBJS))

FLAGS				= -Wall -Wextra -Werror

all: $(NAME)

debug:
	@echo $(SRCS_ARG)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(OBJS_WITH_PATH) $(PATH_OBJECTS) $(HEADERS_COREWAR)
	gcc $(FLAGS) $(OBJS_WITH_PATH) -I $(PATH_HEDES) \
		-L $(PATH_LIBFT) -lft -L $(PATH_LIBFT_PRINTF) -lftprintf -o $@

$(LIBFT): libft

$(LIBFTPRINTF): libftprintf

libft:
	@make -C $(PATH_LIBFT)

libftprintf:
	@make -C $(PATH_LIBFT_PRINTF)

$(OBJS_WITH_PATH): $(PATH_OBJS)%.o:$(PATH_SRCS)%.c $(HEADERS_COREWAR)
	@mkdir -p $(@D)
	@gcc $(FLAGS) -c $< -I $(PATH_LIBFT) -I $(PATH_LIBFT_PRINTF) \
		-I $(PATH_HEDES) -o $@
	@echo "$<  $@"

clean_corewar:
	@make clean -C $(PATH_LIBFT)
	@make clean -C $(PATH_LIBFT_PRINTF)
	@sh $(PATH_SCRIPTS)/print_clean.sh $(NAME)
	@rm -fr $(OBJS_WITH_PATH)
	@sh $(PATH_SCRIPTS)/check_and_del_dir.sh $(PATH_OBJECTS)

clean: clean_corewar

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@make fclean -C $(PATH_LIBFT_PRINTF)
	@sh $(PATH_SCRIPTS)/print_fclean.sh $(NAME)
	@rm -fr $(NAME)

re: fclean all
