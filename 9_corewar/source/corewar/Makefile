# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astamm <astamm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 11:38:51 by wmaykit           #+#    #+#              #
#    Updated: 2020/05/01 10:43:02 by artem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= corewar
FLAGS				= -Wall -Wextra -Werror 


PATH_OBJS			= objects
PATH_LIBFT			= ../../libraries/libft
PATH_LIBFT_PRINTF	= ../../libraries/libftprintf
PATH_SCRIPTS		= ../../scripts/make_scripts
PATH_HEDES			= ./include
PATH_SRCS			= ./source

HEADER_COREWAR		= $(PATH_HEDES)/corewar.h
HEADER_VISU			= $(PATH_HEDES)/visu.h
HEADER_OP			= $(PATH_HEDES)/op.h
HEADERS_COREWAR		= $(HEADER_COREWAR) $(HEADER_OP) $(HEADER_VISU)

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
						  valid_visual.c valid_dump.c valid_n.c valid_server.c \
						  valid_client.c \
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
						  add_option.c options_fetch_bits_flag.c
SRCS_CONSTRDESTR_OPT	= destroy_options.c new_obj_dump.c \
						  destroy_options_list.c new_options_list.c \
						  new_obj_server.c new_obj_client.c

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
SRCS_INTERFACE_PL		= player_memcpy.c player_introduce_yourself.c \
						  player_say_won.c
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
						  players_memcpy.c players_introducing.c
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
SRCS_INTERFACE_MR		= memory_export_dump.c memory_read.c memory_shift.c \
						  memory_write.c
SRCS_CONSTRDESTR_MR		= new_memory.c destroy_memory.c

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
SRCS_GETSET_PAR			= params_get_cycle_to_die.c params_get_cycle.c \
						  param_set_player_live.c \
						  params_get_players_last_live.c
SRCS_PARSING_PAR		= 
SRCS_INTERFACE_PAR		= params_increase_number_checks.c \
						  params_need_decrease_cycle_to_die.c \
						  params_decrease_cycle_to_die.c params_reset.c \
						  params_increase_cycle.c param_increase_oper_live.c
SRCS_VALIDATIONS_PAR	= 
SRCS_CONSTRDESTR_PAR	= new_params.c destroy_params.c

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
SRCS_GETSET_CAR			= carriage_set_id.c carriage_set_oper_code.c \
						  carriage_set_carry.c carriage_set_reg.c \
						  carriage_get_reg.c carriage_set_cycle_live.c \
						  carriage_set_address.c
SRCS_PARSING_CAR		= 
SRCS_INTERFACE_CAR		= carriage_need_set_code.c carriage_skip_code.c \
						  carriage_fetch_code.c carriage_is_die.c
SRCS_VALIDATIONS_CAR	= 
SRCS_CONSTRDESTR_CAR	= new_carriage.c destroy_carriage.c carriage_clone.c

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
SRCS_INTERFACE_CARS		= carriages_add_carige.c carriages_iterator_set_next.c \
						  carriages_have_live.c carriages_delete_carrige.c
SRCS_VALIDATIONS_CARS	= 
SRCS_CONSTRDESTR_CARS	= new_carriages.c destroy_carriages.c \
						  carriages_init_iterator.c destroy_carlst.c 

SRCS_CARS	= $(addprefix $(DIR_DEBUG_CARS)/, $(SRCS_DEBUG_CARS)) \
			  $(addprefix $(DIR_GETSET_CARS)/, $(SRCS_GETSET_CARS)) \
			  $(addprefix $(DIR_PARSING_CARS)/, $(SRCS_PARSING_CARS)) \
			  $(addprefix $(DIR_INTERFACE_CARS)/, $(SRCS_INTERFACE_CARS)) \
			  $(addprefix $(DIR_VALIDATIONS_CARS)/, $(SRCS_VALIDATIONS_CARS)) \
			  $(addprefix $(DIR_CONSTRDESTR_CARS)/, $(SRCS_CONSTRDESTR_CARS))
################################################################################

################################################################################
#							NETWORK											   #
################################################################################
DIR_NET					= network

DIR_GETSET_NET			= get_set
DIR_PACKAGES_NET		= packages
DIR_EXCHANGE_NET		= exchange
DIR_INTERFACE_NET		= interface
DIR_VALIDATIONS_NET		= validations
DIR_CONSTRDESTR_NET		= constr_and_destr
DIR_CONNECTIONS_NET		= connections

SRCS_GETSET_NET			= network_get_servinfo.c
SRCS_PACKAGES_NET		= network_package_free.c network_pack_player.c \
						  net_package_put_header.c net_package_put_end.c \
						  network_pakage_load_from_net.c \
						  network_pakage_get_header.c \
						  network_pakages_realloc_mem.c \
						  net_get_next_pakage.c network_pakage_put_pakage.c \
						  network_unpack_player.c
SRCS_EXCHANGE_NET		= network_recv_players.c network_send_player.c \
						  network_broadcast.c network_fetch_data_to_buff.c
SRCS_INTERFACE_NET		= 
SRCS_VALIDATIONS_NET	= 
SRCS_CONSTRDESTR_NET	= network_connect_to_server.c connect_destroy.c \
						  network_get_connect_clients.c
SRCS_CONNECTIONS_NET	= network_take_connections.c network_stop_conections.c \
						  network_user_verification.c network_verification.c 


SRCS_NET	= $(addprefix $(DIR_GETSET_NET)/, $(SRCS_GETSET_NET)) \
			  $(addprefix $(DIR_PACKAGES_NET)/, $(SRCS_PACKAGES_NET)) \
			  $(addprefix $(DIR_EXCHANGE_NET)/, $(SRCS_EXCHANGE_NET)) \
			  $(addprefix $(DIR_INTERFACE_NET)/, $(SRCS_INTERFACE_NET)) \
			  $(addprefix $(DIR_VALIDATIONS_NET)/, $(SRCS_VALIDATIONS_NET)) \
			  $(addprefix $(DIR_CONSTRDESTR_NET)/, $(SRCS_CONSTRDESTR_NET)) \
			  $(addprefix $(DIR_CONNECTIONS_NET)/, $(SRCS_CONNECTIONS_NET))
################################################################################

################################################################################
#							OPERATIONS										   #
################################################################################
DIR_OPR					= operation

DIR_DEBUG_OPR			= debug
DIR_GETSET_OPR			= get_set
DIR_PARSING_OPR			= parsing
DIR_INTERFACE_OPR		= interface
DIR_VALIDATIONS_OPR		= validations
DIR_CONSTRDESTR_OPR		= constr_and_destr

SRCS_DEBUG_OPR			= 
SRCS_GETSET_OPR			= operation_get_cyle_exec.c
SRCS_PARSING_OPR		= 
SRCS_INTERFACE_OPR		= operation_exec.c operation_valid_code_oper.c \
						  operation_valid_code_type_arg.c \
						  operation_fetch_args.c operation_ld.c \
						  operation_and.c operation_live.c operation_st.c \
						  operation_add.c operation_sub.c operation_or.c \
						  operation_xor.c operation_zjmp.c operation_ldi.c \
						  operation_sti.c operation_fork.c operation_lld.c \
						  operation_lldi.c operation_lfork.c\
						  operation_aff.c
SRCS_VALIDATIONS_OPR	= 
SRCS_CONSTRDESTR_OPR	= 

SRCS_OPR	= $(addprefix $(DIR_DEBUG_OPR)/, $(SRCS_DEBUG_OPR)) \
			  $(addprefix $(DIR_GETSET_OPR)/, $(SRCS_GETSET_OPR)) \
			  $(addprefix $(DIR_PARSING_OPR)/, $(SRCS_PARSING_OPR)) \
			  $(addprefix $(DIR_INTERFACE_OPR)/, $(SRCS_INTERFACE_OPR)) \
			  $(addprefix $(DIR_VALIDATIONS_OPR)/, $(SRCS_VALIDATIONS_OPR)) \
			  $(addprefix $(DIR_CONSTRDESTR_OPR)/, $(SRCS_CONSTRDESTR_OPR))
################################################################################

################################################################################
#							VISUALIZATION									   #
################################################################################
DIR_VISU				= visualization

DIR_SEND_PCKG_VISU		= send_package
DIR_ACCEPT_PCKG_VISU	= accept_package
DIR_VISU_PCKG_VISU		= visu_package
DIR_OTHER_VISU			= other

SRCS_SEND_PCKG_VISU			= package_init_memory.c package_end_game.c \
							package_write_in_mem.c package_end_init.c \
							package_change_carriage_address.c \
							send_package_init_carriages.c \
							send_package_new_carriage.c \
							packages_init_corewar.c \
							package_init_players.c package_increase_cycle.c \
							package_decrease_ctd.c package_death_carriage.c \
							package_player_say_live.c package_winning_player.c

SRCS_ACCEPT_PCKG_VISU		= processing_package_for_init.c \
							accept_package_change_carriage_addres.c \
							accept_package_new_carriage.c init_arena_for_visu.c \
							init_players_for_visu.c init_carriage_for_visu.c 

SRCS_VISU_PCKG_VISU			= visu_run.c rendering.c \
							visu_print_arena.c visu_write_in_mem.c \
							visu_change_carriage_address.c \
							visu_new_carriage.c constructor_windows.c \
							visu_increase_cycles.c visu_decrease_ctd.c \
							print_init_carriage.c visu_death_carriage.c \
							print_init_player.c visu_player_say_live.c \
							visu_winning_player.c

SRCS_OTHER_VISU				= visu_init.c destroy_visu.c \
							get_package_for_visu.c destroy_package_visu.c \
							set_start_end_code_players.c set_color_players.c \
							init_color_pairs.c set_color_carriages.c set_y_x.c \
							keyboard_control.c key_processing_visu.c
							
SRCS_VISU	  = $(addprefix $(DIR_SEND_PCKG_VISU)/, $(SRCS_SEND_PCKG_VISU)) \
				$(addprefix $(DIR_ACCEPT_PCKG_VISU)/, $(SRCS_ACCEPT_PCKG_VISU)) \
				$(addprefix $(DIR_VISU_PCKG_VISU)/, $(SRCS_VISU_PCKG_VISU)) \
				$(addprefix $(DIR_OTHER_VISU)/, $(SRCS_OTHER_VISU))
################################################################################

################################################################################
#							COREWAR											   #
################################################################################
DIR_CR					= corewar

DIR_MODS_CR				= mods
DIR_DEBUG_CR			= debug
DIR_INTERFACE_CR		= interface
DIR_CONSTRDESTR_CR		= constr_and_destr

SRCS_MODS_CR			= corewar_client_mode.c corewar_server_mode.c \
						  corewar_visual_mode.c corewar_default_mode.c
SRCS_DEBUG_CR			= debug_print_memory_fd.c
SRCS_INTERFACE_CR		= print_usage.c print_help.c corewar.c \
						  is_suitable_file.c corewar_exec.c corewar_run.c \
						  corewar_check.c corewar_core.c \
						  corewar_honoring_the_winner.c
SRCS_CONSTRDESTR_CR		= new_corewar.c destroy_corewar.c corewar_resolve.c

SRCS_CR     = $(addprefix $(DIR_MODS_CR)/, $(SRCS_MODS_CR)) \
			  $(addprefix $(DIR_DEBUG_CR)/, $(SRCS_DEBUG_CR)) \
			  $(addprefix $(DIR_INTERFACE_CR)/, $(SRCS_INTERFACE_CR)) \
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
			  $(addprefix $(DIR_OPR)/,$(SRCS_OPR))	\
			  $(addprefix $(DIR_CR)/,$(SRCS_CR))	\
			  $(addprefix $(DIR_ERR)/,$(SRCS_ERR))	\
			  $(addprefix $(DIR_NET)/,$(SRCS_NET))	\
  			  $(addprefix $(DIR_VISU)/,$(SRCS_VISU))

SRCS_WITH_PATH		= $(SRCS_DEMO) main.c

SRCS_WITH_FULL_PATH = $(addprefix ./source/,$(SRCS_WITH_PATH))

OBJS				= $(SRCS_WITH_PATH:.c=.o)

OBJS_WITH_PATH		= $(addprefix $(PATH_OBJS)/,$(OBJS))

all: libft libftprintf init_loading $(NAME)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(OBJS_WITH_PATH) $(PATH_OBJECTS) $(HEADERS_COREWAR)
	@gcc  $(FLAGS) $(OBJS_WITH_PATH) -I $(PATH_HEDES) \
		-L $(PATH_LIBFT) -lft -L $(PATH_LIBFT_PRINTF) -lftprintf -lncurses -lpthread -o $(NAME)
	@printf "\r\e[2K"
	@echo "Done compilling $(NAME)!"
	@make destroy_loading --no-print-directory

init_loading:
	@$(PATH_SCRIPTS)/init_loading_bar.py "$(OBJS_WITH_PATH)" "$(SRCS_WITH_FULL_PATH)" "$(HEADERS_COREWAR)" "$(NAME)"

destroy_loading:
	@$(PATH_SCRIPTS)/destroy_loading_bar.py

$(LIBFT): libft

$(LIBFTPRINTF): libftprintf

libft:
	@make -C $(PATH_LIBFT)

libftprintf:
	@make -C $(PATH_LIBFT_PRINTF)

$(OBJS_WITH_PATH): $(PATH_OBJS)%.o:$(PATH_SRCS)%.c $(HEADERS_COREWAR)
	@mkdir -p $(@D)
	@$(PATH_SCRIPTS)/print_step_loading.py $(<F)
	@gcc $(FLAGS) -c $< -I $(PATH_LIBFT) -I $(PATH_LIBFT_PRINTF) \
		-I $(PATH_HEDES) -o $@

clean_corewar:
	@make clean -C $(PATH_LIBFT)
	@make clean -C $(PATH_LIBFT_PRINTF)
	@rm -rf $(PATH_OBJS)

clean: clean_corewar

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@make fclean -C $(PATH_LIBFT_PRINTF)
	@rm -fr $(NAME)

re: fclean all

.PHONY:  init_loading compiling destroy_loading all re clean fclean libft libftprintf
