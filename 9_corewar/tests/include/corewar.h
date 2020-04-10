/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:31:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/02/03 20:01:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "op.h"
# include "libft.h"
# include "libftprintf.h"

# define PROGRAMM_NAME		"corewar"
# define LOG_FILE_NAME		"corewar_log.txt"
# define HEDER_SIZE			(PROG_NAME_LENGTH + COMMENT_LENGTH + (4 * 4))
# define MAX_SIZE_FILE		(CHAMP_MAX_SIZE + HEDER_SIZE)
# define MIN_SIZE_FILE		(HEDER_SIZE)
# define MAGIC_SIZE			(sizeof(unsigned))
# define CODE_SIZE			(4)
# define NULL_SIZE			(4)

# define MIN_PLAYERS		1

# define BUFF_SIZE_EXIT		80

# define SIGN_OPTIONS		'-'

# define PL_SUCCESS 			0
# define PL_PARSING_ERROR 		1
# define PL_LOADFILE_ERROR 		2
# define PL_VALIDATION_ERROR	3

/*
** WARNING!!! When adding options to the program, be sure to follow the order!
** First add the option name to the OPTION_EXTRA macro, then add the validation
** function to the VALID_EXTRA macro in same index. If it is set to NULL,
** delete it. In OPTIONS_EXTRA, the terminator ("") is required at the end.
*/
# define OPTIONS_EXTRA		""
# define VALID_EXTRA		NULL
# define NEW_OPT_EXTRA		NULL

# define OPTIONS_WITH_NUM	"dump", "n", ""
# define OPTIONS			"visual", ""
# define MAX_LEN_NAME_OPT	10

# define VALID_OPT_WITH_NUM	valid_dump, valid_n
# define VALID_OPT			valid_visual
# define VALID_FUNCS		VALID_OPT_WITH_NUM, VALID_OPT, VALID_EXTRA

# define NEW_OPT_WITH_NUM	new_obj_dump, NULL
# define NEW_OPT			NULL
# define NEW_OPT_FUNCS		NEW_OPT_WITH_NUM, NEW_OPT, NEW_OPT_EXTRA

# define NO_OPTIONS			-1

# define E_NO_MEM			"Something is wrong with memory"
# define NO_ORDER_PLAYER	-1

typedef	enum	e_boolean
{
	True = 1,
	False = !True
}				t_boolean;

typedef struct	s_file
{
	int				fd;
	char			*path;
	void			*entry;
	long			size;
	t_boolean		open;
}				t_file;

typedef struct	s_valid_args
{
	int			argc;
	char		**argv;
	int			current_arg;
	int			amount_files;
	unsigned	order_files;
}				t_valid_args;

typedef struct	s_options_list
{
	int						id;
	void					*option_obj;
	char					*name;
	struct	s_options_list	*next;
}				t_options_list;

typedef struct	s_player
{
	t_file			*file;
	char			*name;
	char			*comment;
	int				order;
	int				size_bytes;
	unsigned char	mem_champion[CHAMP_MAX_SIZE];
}				t_player;

typedef struct	s_players
{
	t_player	*player[MAX_PLAYERS];
	int			amount;
}				t_players;

typedef struct	s_args_obj
{
	t_options_list	*options;
	t_players		*players;
}				t_args_obj;

typedef struct		s_memory
{
	unsigned char	*mem;
	int				*segments;
	int				amount_segments;
	size_t			size;
}					t_memory;

typedef struct	s_params
{
	const t_player	*pl_live;
	long			cycle;
	int				num_oper_live;
	int				cycles_to_die;
	int				number_checks;
}				t_params;

typedef int		t_reg;

typedef struct	s_carriage
{
	int			id;
	t_boolean	carry;
	int			code;
	long		cycle_live;
	int			cycle_to_exec;
	int			address;
	int			size_curr_oper;
	t_reg		reg[REG_NUMBER];
}				t_carriage;

typedef struct	s_carlst
{
	t_carriage		*carriage;
	struct s_carlst	*next;
}				t_carlst;

typedef struct	s_carriages
{
	t_carlst 	*carriages;
	int			amount;
}				t_carriages;

typedef struct	s_itercarr
{
	t_boolean	have_carriage;
	t_carlst	*current_lst;
	t_carriage	*carriage;
}				t_itercarr;

typedef enum	e_oper
{
	live = 0,
	ld = 1,
	st = 2,
	add = 3,
	sub = 4,
	and = 5,
	or = 6,
	xor = 7,
	zjump = 8,
	ldi	= 9,
	sti	= 10,
	fork = 11,
	lld	= 12,
	lldi = 13,
	first_oper = live,
	last_oper = lldi
}				t_oper;

typedef struct	s_corewar
{
	t_players		*players;
	t_options_list	*options;
	t_memory		*memory;
	t_params		*params;
	t_carriages		*carriages;
}				t_corewar;


typedef void				(*func_valid_arg)(t_valid_args *);
typedef func_valid_arg		t_valid_arg_func[];

typedef void				*(*func_new_opt_obj)(int*, char**);
typedef func_new_opt_obj	t_funcs_new_opt_obj[];

/*
** Class Arguments
*/
t_args_obj		*new_args_obj(int i_argc, char **i_argv);
void			destroy_args_obj(t_args_obj **m_args);
void			*get_option_obj(t_args_obj *m_args, char *i_options);

void			add_new_options_to_arg_obj(t_args_obj *m_args, int *m_index_arg,
				char **i_argv);
void			add_file_new_player_to_arg_obj(t_args_obj *m_args,
				char *i_path_fl);
t_valid_args	new_valid_obj(int argc, char **argv);
t_boolean		validation_args(int argc, char **argv);
t_players		*pop_players(t_args_obj *m_args);
t_options_list  *pop_options(t_args_obj *m_args);

void			valid_visual(t_valid_args *m_validation_object);
void			valid_dump(t_valid_args *m_validation_object);
void			valid_n(t_valid_args *m_validation_object);

void			debug_print_args_obj(t_args_obj *i_args);

/*
** Class Options
*/
void			destroy_options_list(t_options_list **m_list);

void			destroy_options(t_options_list **m_top);
void			*new_obj_dump(int *m_index_arg, char **i_argv);

t_options_list  *new_options_list(char *i_name_options, int *m_index_arg,
																char **i_argv);
void			add_option(t_options_list **m_opt, char *i_opt_name,
															void *i_opt_obj);
int				get_id_options(char *i_options);
t_boolean   	is_options(char *i_options);
t_boolean		is_options_player(char *i_options);

/*
** Class Player
*/
t_boolean		player_validation(t_player *m_pl);
t_boolean		player_parsing(t_player *m_pl);

t_player		*new_player(char *i_path, int i_order);
int				init_player(t_player *m_player);
void			destroy_player(t_player **m_player);

void			player_memcpy(t_player *i_player, void *m_dst);

int				player_get_size(t_player *i_player);

void			debug_print_player(t_player *i_player, int indent, int i_space);

/*
** Class Players
*/
t_boolean		players_validation(t_players *m_pls);

void			destroy_players(t_players **m_players);
t_players		*new_players(void);
t_boolean		init_players(t_players *m_players);

void			push_player_to_players(t_players *m_players, t_player *i_player,
																int i_oreder);
void			players_memcpy(t_players *i_pls, int i_order, void *m_dst);
void			add_to_players(t_players *m_players, t_player *i_player);
int				players_get_amount(t_players *i_players);
t_player		*players_get_player(t_players *i_players, int i_order);

void    		debug_print_players(t_players *i_players, int indent,
																int i_space);

/*
** Class Print
*/
void			print_space(int i_amount);
void			print_memory(void *i_mem, size_t i_size);
void			print_line(char c, int size, t_boolean new_line);

/*
** Class File
*/
t_file			*new_file(char *i_path);
void			destroy_file(t_file **m_file);

void			file_close(t_file *m_file);
t_boolean		load_file(t_file *m_file);
t_boolean		file_has_entry(t_file *i_file);
t_boolean		file_open(t_file *m_file, int i_oflag, ...);

long int		file_get_size(t_file *m_file, char *i_units);
const char		*file_get_path(t_file *i_file);
const void		*file_get_entry(t_file *i_file);

void			debug_print_file(t_file *i_file, int indent, int i_space);

/*
** Class Number
*/
t_boolean		is_overflow(int i_number, char *i_number_ascii);
t_boolean		is_number(char *i_string);
unsigned		number_reverse_mem(unsigned i_origin_num);

/*
** Class FT_error
*/
void		save_error_to_log(char *i_massage1, char *i_massage2);
void		ft_exit(char *error_massage);

/*
** Class Memory
*/
t_memory		*new_memory(t_players *i_players);

void			mamory_export_dump(t_memory *i_mem, int i_fd, int i_num_octets);
void			memory_read(t_memory *i_m, int i_addr, void *m_dst, int i_size);

int				memory_get_size(t_memory *i_mem);
int				memory_get_amount_segments(t_memory *i_mem);
int				memory_get_address_segment(t_memory *i_mem, int i_segment);

/*
** Class Params
*/
t_params	*new_params(t_players *i_players);

/*
** Class Carriages
*/
t_carriages		*new_carriages(t_memory *i_mem);
void			destroy_carriages(t_carriages **m_carriages);

t_boolean		carriages_add_carige(t_carriages *m_carrs, t_carriage *m_carr);


/*
** Class Carriage
*/
t_carriage      *new_carriage(t_reg i_data, int i_address);
void			destroy_carriage(t_carriage **m_carriage);
void			carriages_init_iterator(t_carriages *i_crrs, t_itercarr *m_itr);

t_boolean		carriage_need_set_code(t_carriage *i_carriage);

t_boolean		carriage_set_id(t_carriage *i_carriage, int i_id);
void			carriages_iterator_set_next(t_itercarr *m_iterator);
void			carriage_set_oper_code(t_carriage *m_crr, t_memory *i_mem);


/*
** Class Corewar
*/
t_corewar		*new_corewar(t_args_obj *m_args);
void			print_usage(void);
void			corewar(int argc, char **argv);
t_boolean		is_suitable_file(char *i_path_to_file);


#endif
