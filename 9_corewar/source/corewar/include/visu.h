/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:51:51 by astamm            #+#    #+#             */
/*   Updated: 2020/03/17 17:26:41 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <stdlib.h>
# include <unistd.h>
# include <ncurses.h>
# include "libft.h"
# include "op.h"
# include <pthread.h>

# define ARENA_HEIGHT 							66
# define ARENA_WIDTH 							195

# define DASHBOARD_HEIGHT 						46
# define DASHBOARD_WIDTH 						60

# define INFO_HEIGHT 							20
# define INFO_WIDTH 							DASHBOARD_WIDTH

# define PAUSE_STRING							"** PAUSED ** "
# define RUNNING_STRING							"<< RUNNING >>"
# define MAX_SPEED_VISU							1000
# define DEFAULT_SPEED_VISU						50

# define AND_MEM_CARRIAGES						1024
# define BYTES_IN_STR 							64

# define AMOUNT_COLOR_PAIRS						7
# define COLOR_PAIR_GRAY_VISU					7
# define COLOR_PAIR_WHITE_VISU					15

/*
** Сoordinates Info and Dashboard
*/
# define INFO_PAUSE_RUN_Y 						2
# define INFO_SPEED_Y 							4
# define INFO_SPEED_X 							23

# define DASHBOARD_X 							2
# define DASHBOARD_CYCLE_Y 						2
# define DASHBOARD_CYCLE_X 						11

# define DASHBOARD_PROCESSES_Y					DASHBOARD_CYCLE_Y + 2
# define DASHBOARD_PROCESSES_X 					15

# define DASHBOARD_CTD_Y 						DASHBOARD_PROCESSES_Y + 2
# define DASHBOARD_CTD_X 						18

# define DASHBOARD_CYCLE_DELTA_Y 				DASHBOARD_CTD_Y + 2
# define DASHBOARD_NBR_LIVE_Y 					DASHBOARD_CYCLE_DELTA_Y + 2
# define DASHBOARD_MAX_CHECKS_Y 				DASHBOARD_NBR_LIVE_Y + 2

# define DASHBOARD_PLAYER_1_Y 					DASHBOARD_MAX_CHECKS_Y + 3
# define DASHBOARD_PLAYER_1_LIVE_Y 				DASHBOARD_PLAYER_1_Y + 1
# define DASHBOARD_PLAYER_1_LIVE_X 				17

/*
**		Codes packages
*/
# define SIZE_CODE_PACKAGE						2
# define CODE_PACKAGE_END_GAME					0xffee
# define CODE_PACKAGE_END_INIT					0xffeb
# define CODE_PACKAGE_MEMORY					0xff01
# define CODE_PACKAGE_WRITE_IN_MEM				0xff02

# define CODE_PACKAGE_NEW_CARRIAGE				0xff03
# define CODE_PACKAGE_DEATH_CARRIAGE			0xff04
# define CODE_PACKAGE_CHANGE_CARRIAGE_ADDRESS	0xff05

# define CODE_PACKAGE_CHANGE_CTD				0xff06
# define CODE_PACKAGE_CHANGE_CYCLES				0xff07

# define CODE_PACKAGE_PLAYER					0xff08
# define CODE_PACKAGE_PLAYER_SAY_LIVE			0xff09
# define CODE_PACKAGE_WINNING_PLAYER			0xff10

typedef struct	s_package
{
	int				code_package;
	int				size_package;
	unsigned char	*content;
}				t_package;

typedef struct	s_visu_player
{
	char	*name;
	char	*comment;
	int		number;
	int		code_size_player;
	int		byte_start_code;
	int		byte_end_code;
	int		color_pair;
}				t_visu_player;

typedef struct	s_visu_gamers
{
	t_visu_player	player[MAX_PLAYERS];
	int				amount;
}				t_visu_gamers;

typedef struct	s_visu_carriage
{
	int		id;
	int		address;
	int		number_player;
	int		color_pair;
	int		color_pair_txt;
	int		color_pair_player;
	int		y;
	int		x;
	char	original_str[3];
}				t_visu_carriage;

typedef struct	s_visu_carriagess
{
	t_visu_carriage	**carriages;
	int				memory_allocated;
	int				amount_maloc_car;
	int				amount;
}				t_visu_carriagess;

typedef struct	s_visu_keyboard_control
{
	t_boolean		exit;
	int				speed;
	t_boolean		pause;
	useconds_t		microseconds;
	WINDOW			*w_info;
}				t_visu_keyboard;

typedef struct	s_visu
{
	unsigned char		*arena;
	int					size_arena;
	int					sqrt_arena;
	int					amount_string;
	int					bytes_in_last_str;
	t_boolean			exit;
	t_visu_gamers		gamers;
	t_visu_carriagess	struct_carriages;
	WINDOW				*w_arena;
	WINDOW				*w_dashboard;
	WINDOW				*w_info;
	pthread_t			thread;
	t_visu_keyboard		*keyboard;
}				t_visu;

/*
**			Send packages
*/
void			package_init_memory(unsigned char *mem, size_t mem_size,
																		int fd);
void			package_change_carriage_address(int id, int address, int fd);
void			package_end_game(int fd);
void			package_increase_cycle(long cycle, int fd);
void			package_decrease_ctd(int cycle_to_die, int fd);
void			package_end_init(int fd);
void			package_death_carriage(int id_carriage, int amount_carriages,
																		int fd);
void			package_player_say_live(int player, long cycle, int fd);
void			package_winning_player(int number_player, int fd);

/*
**			Accept packages && Initialization
*/
void			processing_package_for_init(t_package *package, t_visu *visu);
void			init_arena_for_visu(t_package *package, t_visu *visu);
void			init_players_for_visu(t_package *package, t_visu *visu);
void			init_carriage_for_visu(t_package *package,
					t_visu_carriagess *struct_carriages, WINDOW *w_dashboard);
void			accept_package_new_carriage(t_package *package,
							t_visu_carriagess *struct_carriages, t_visu *visu);
void			accept_package_change_carriage_addres(t_package *package,
							t_visu_carriagess *struct_carriages, t_visu *visu);

/*
**			Visualize packages
*/
void			rendering(t_visu *visu, t_package *package);
void			visu_write_in_mem(t_visu *visu, t_package *package);
void			visu_new_carriage(t_visu *visu, t_visu_carriage *carriage);
void			visu_change_carriage_address(t_visu *visu,
													t_visu_carriage *carriage);
void			visu_increase_cycles(t_package *package, t_visu *visu);
void			visu_decrease_ctd(t_package *package, t_visu *visu);
void			visu_death_carriage(t_package *package, t_visu *visu,
										t_visu_carriagess *struct_carriages);
void			visu_player_say_live(t_package *package, t_visu *visu);
void			visu_winning_player(t_package *package, t_visu *visu);

/*
**			Print something
*/
void			print_arena(t_visu *visu);
void			print_one_str_in_arena(t_visu *visu, unsigned char *mem,
													int y, int *current_byte);
void			print_init_carriage(t_visu *visu);
void			print_init_player(t_visu *visu);

/*
**			Other
*/
void			visu_run (int fd);
t_visu			visu_init(int fd);
void			constructor_windows(t_visu *visu);
t_package		get_package(int fd);
void			destroy_visu(t_visu *visu);
void			destroy_package_visu(t_package *package);
void			set_start_end_code_players(t_visu_gamers *gamers,
										t_visu_carriagess *struct_carriages);
void			init_color_pairs(void);
void			set_color_players(t_visu_gamers *gamers);
void			set_color_carriages(t_visu *visu);
void			set_y_x(int *y, int *x, int byte_number, t_visu *visu);
void			*keyboard_control(void *keyboard_control);
void			key_processing_visu(t_visu *visu, t_package *package,
															int *prev_speed);

#endif
