/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:31:07 by wmaykit           #+#    #+#             */
/*   Updated: 2020/05/01 10:42:46 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <pthread.h>
# include <arpa/inet.h>
# include <poll.h>
# include "op.h"
# include "visu.h"
# include "libft.h"
# include "libftprintf.h"

# define PROGRAMM_NAME			"corewar"
# define LOG_FILE_NAME			"corewar_log.txt"
# define HEDER_SIZE				(PROG_NAME_LENGTH + COMMENT_LENGTH + (4 * 4))
# define MAX_SIZE_FILE			(CHAMP_MAX_SIZE + HEDER_SIZE)
# define MIN_SIZE_FILE			(HEDER_SIZE)
# define MAGIC_SIZE				(sizeof(unsigned))
# define CODE_SIZE				(4)
# define NULL_SIZE				(4)

# define MIN_PLAYERS			1

# define BUFF_SIZE_EXIT			80
# define BUFF_SIZE				1024

# define SIGN_OPTIONS			'-'

# define PL_SUCCESS				0
# define PL_PARSING_ERROR		1
# define PL_LOADFILE_ERROR		2
# define PL_VALIDATION_ERROR	3

/*
** WARNING!!! When adding options to the program, be sure to follow the order!
** First add the option name to the OPTION_EXTRA macro, then add the validation
** function to the VALID_EXTRA macro in same index. If it is set to NULL,
** delete it. In OPTIONS_EXTRA, the terminator ("") is required at the end.
*/
# define OPTIONS_EXTRA			"server", "client", "aff", ""
# define VALID_EXTRA			valid_server, valid_client, NULL, NULL
# define NEW_OPT_EXTRA			new_obj_server, new_obj_client, NULL, NULL

# define OPTIONS_WITH_NUM		"dump", "n", ""
# define OPTIONS				"visual", ""
# define MAX_LEN_NAME_OPT		10

# define O_DUMP32				0x00000001
# define O_DUMP64				0x80000000
# define O_DUMP					(O_DUMP32 | O_DUMP64)
# define O_VISU					0x00000004
# define O_SERVER				0x00000008
# define O_CLIENT				0x00000010
# define O_AFF					0x00000020

# define VALID_OPT_WITH_NUM		valid_dump, valid_n
# define VALID_OPT				valid_visual
# define VALID_FUNCS			VALID_OPT_WITH_NUM, VALID_OPT, VALID_EXTRA

# define NEW_OPT_WITH_NUM		new_obj_dump, NULL
# define NEW_OPT				NULL
# define NEW_OPT_FUNCS			NEW_OPT_WITH_NUM, NEW_OPT, NEW_OPT_EXTRA

# define NO_OPTIONS				-1

# define E_NO_MEM				"Something is wrong with memory"
# define NO_ORDER_PLAYER		-1

# define SIZE_OPER_CODE			1
# define SIZE_ARG_TYPE_CODE		1

# define MIN_REG				1

# define OPER_SUCCESS			0
# define OPER_ERROR				-1

# define MAX_LEN_PASS			20

# define STANDART_PORT			"3490"
# define NET_OK					COREWAR_EXEC_MAGIC
# define NET_BACKLOG			10
# define NET_BUFF_SIZE			4500
# define NET_DELAY				20000000

# define PAKEGE_HEDER_SIZE		12
# define PAKEGE_END_SIZE		8
# define PAKEGE_PLAYER_CODE		0x00000001
# define PAKEGE_SIGN_BEGIN		0x12345678
# define PAKEGE_SIGN_END		0x87654321

# define PAKEGE_ERROR_DIFCOD_F	0x00000001

# define NET_BUF_FLAG_MEMAL		0x00000001
# define NET_BUF_FLAG_CONTAIN	0x00000100

typedef struct	s_pak_header
{
	unsigned	pakage_size;
	unsigned	pakage_code;
}				t_pak_header;

typedef struct	s_buff
{
	void		*data;
	size_t		size_data;
	size_t		size_memory;
}				t_buff;

typedef struct	s_pak_net
{
	void		*data;
	int			code;
	int			size;
	unsigned	error_f;
}				t_pack_net;

typedef struct	s_net_buff
{
	struct pollfd	fds;
	unsigned char	*entry;
	unsigned char	*pakage_out;
	t_boolean		empty;
	int				index_stop;
	int				index_uploaded_to;
	unsigned		flags;
	int				mem_size;
}				t_net_buff;

typedef	struct	s_server
{
	int		id;
	char	port[6];
	char	pass[MAX_LEN_PASS + 1];
	int		fd_out;
	int		fd_in;
	int		amount_players;
}				t_server;

typedef	struct	s_client
{
	int		id;
	char	port[6];
	char	pass[MAX_LEN_PASS + 1];
	int		fd;
	char	ip_server[INET6_ADDRSTRLEN];
}				t_client;

enum			e_arg_type
{
	flag_type = 0,
	size_arg = 1,
	code_arg = 2
};

typedef enum	e_args
{
	arg1 = 0,
	arg2 = 1,
	arg3 = 2,
	first_arg = arg1,
	last_arg = arg3
}				t_args;

typedef struct	s_code
{
	int				oper;
	unsigned char	arg_type[3][3];
	int				args[3];
	int				size;
	t_boolean		valid;
}				t_code;

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
	unsigned	mods;
	int			current_arg;
	int			amount_files;
	unsigned	order_files;
}				t_valid_args;

typedef struct	s_options_list
{
	int						id;
	void					*option_obj;
	char					*name;
	struct s_options_list	*next;
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

typedef struct	s_memory
{
	unsigned char	*mem;
	int				*segments;
	int				amount_segments;
	size_t			size;
}				t_memory;

typedef struct	s_params
{
	t_player		*pl_live;
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
	struct s_carlst	*prev;
}				t_carlst;

typedef struct	s_carriages
{
	t_carlst	*carriages;
	int			amount;
}				t_carriages;

typedef struct	s_itercarr
{
	t_boolean	have_carriage;
	t_carriage	*carriage;
	t_carlst	**head_lst;
	t_carlst	*prev_lst;
	t_carlst	*current_lst;
	t_carlst	*next_lst;
	int			*amount_carriages;
}				t_itercarr;

typedef enum	e_oper
{
	live_op = 1,
	ld_op = 2,
	st_op = 3,
	add_op = 4,
	sub_op = 5,
	and_op = 6,
	or_op = 7,
	xor_op = 8,
	zjmp_op = 9,
	ldi_op = 10,
	sti_op = 11,
	fork_op = 12,
	lld_op = 13,
	lldi_op = 14,
	lfork_op = 15,
	aff_op = 16,
	first_oper = live_op,
	last_oper = aff_op
}				t_oper;

typedef struct	s_corewar
{
	t_players		*players;
	t_options_list	*options;
	t_memory		*memory;
	t_params		*params;
	t_carriages		*carriages;
	int				fd;
}				t_corewar;

typedef	struct	s_connect
{
	int				sockfd;
	int				connect_players;
	int				max_players;
	struct pollfd	connect_client[MAX_PLAYERS];
	int				connectfd[MAX_PLAYERS];
	char			pass[MAX_LEN_PASS + 1];
	t_players		*players;
	t_boolean		connect;
	int				out_fd;
	struct pollfd	in_fds;
	pthread_t		thread[4];
}				t_connect;

typedef void				(*t_func_valid_arg)(t_valid_args *);
typedef t_func_valid_arg	t_valid_arg_func[];

typedef void				*(*t_func_new_opt_obj)(int*, char**);
typedef t_func_new_opt_obj	t_funcs_new_opt_obj[];

/*
** Class Arguments
*/
t_args_obj		*new_args_obj(int i_argc, char **i_argv);
void			destroy_args_obj(t_args_obj **m_args);
void			*get_option_obj(t_options_list *m_args, char *i_options);

void			add_new_options_to_arg_obj(t_args_obj *m_args, int *m_index_arg,
				char **i_argv);
void			add_file_new_player_to_arg_obj(t_args_obj *m_args,
				char *i_path_fl);
t_valid_args	new_valid_obj(int argc, char **argv);
t_boolean		validation_args(int argc, char **argv);
t_players		*pop_players(t_args_obj *m_args);
t_options_list	*pop_options(t_args_obj *m_args);

void			valid_visual(t_valid_args *m_validation_object);
void			valid_dump(t_valid_args *m_validation_object);
void			valid_server(t_valid_args *m_valid);
void			valid_client(t_valid_args *m_valid);
void			valid_n(t_valid_args *m_validation_object);

void			debug_print_args_obj(t_args_obj *i_args);

/*
** Class Options
*/
void			destroy_options_list(t_options_list **m_list);

void			destroy_options(t_options_list **m_top);
void			*new_obj_dump(int *m_index_arg, char **i_argv);
void			*new_obj_server(int *m_index_arg, char **i_argv);
void			*new_obj_client(int *m_index_arg, char **i_argv);

t_options_list	*new_options_list(char *i_name_options, int *m_index_arg,
																char **i_argv);
void			add_option(t_options_list **m_opt, char *i_opt_name,
															void *i_opt_obj);
unsigned int	options_fetch_bits_flag(t_options_list *i_options);
int				get_id_options(char *i_options);
t_boolean		is_options(char *i_options);
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
void			player_introduce_yourself(t_player *i_player);
void			player_say_won(t_player *i_player);

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
void			players_introducing(t_players *i_players);

int				players_get_amount(t_players *i_players);
t_player		*players_get_player(t_players *i_players, int i_order);

void			debug_print_players(t_players *i_players, int indent,
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
void			save_error_to_log(char *i_massage1, char *i_massage2);
void			ft_exit(char *error_massage);

/*
** Class Memory
*/
t_memory		*new_memory(t_players *i_players);
void			destroy_memory(t_memory **del_memory);

void			memory_export_dump(t_memory *i_mem, int i_fd, int i_num_octets);
void			memory_read(t_memory *i_m, int i_addr, void *m_dst, int i_size);
void			memory_write(t_memory *i_m, int i_add, void *m_src, int i_siz);
int				memory_shift(int i_address, int i_shift_bytes);

int				memory_get_size(t_memory *i_mem);
int				memory_get_amount_segments(t_memory *i_mem);
int				memory_get_address_segment(t_memory *i_mem, int i_segment);

/*
** Class Params
*/
t_params		*new_params(t_players *i_players);
void			destroy_params(t_params **del_params);

void			params_reset(t_params *m_params);
void			params_increase_cycle(t_params *m_params);
void			params_decrease_cycle_to_die(t_params *m_params);
void			params_increase_number_checks(t_params *m_params);
void			param_increase_oper_live(t_params *m_params);
t_boolean		params_need_decrease_cycle_to_die(t_params *i_params);

int				params_get_cycle_to_die(t_params *i_params);
int				params_get_cycle(t_params *i_params);
t_player		*params_get_players_last_live(t_params *i_params);
void			param_set_player_live(t_params *m_params, t_player *i_live_pl);

/*
** Class Carriages
*/
t_carriages		*new_carriages(t_memory *i_mem);
void			destroy_carriages(t_carriages **m_carriages);
void			destroy_carlst(t_carlst **m_lst_for_del);
void			carriages_init_iterator(t_carriages *i_crrs, t_itercarr *m_itr);

t_boolean		carriages_add_carige(t_carriages *m_carrs, t_carriage *m_carr);
t_boolean		carriages_have_live(t_carriages *i_carriages);
void			carriages_delete_carrige(t_itercarr *m_iterator);

/*
** Class Carriage
*/
t_carriage		*new_carriage(t_reg i_data, int i_address);
t_carriage		*carriage_clone(t_carriage *m_carriage);
void			destroy_carriage(t_carriage **m_carriage);

t_boolean		carriage_is_die(t_carriage *i_c, int i_curr_ccl, int i_die_ccl);
t_boolean		carriage_need_set_code(t_carriage *i_carriage);
t_code			carriage_fetch_code(t_carriage *m_carr, t_memory *i_mem);
void			carriage_skip_code(t_carriage *m_carriage, t_code *i_code);

t_boolean		carriage_set_id(t_carriage *i_carriage, int i_id);
void			carriage_set_carry(t_carriage *m_carriage, t_boolean i_carry);
void			carriage_set_address(t_carriage *m_carriage, int i_address);
void			carriage_set_reg(t_carriage *m_carriage, int i_reg, int i_data);
int				carriage_get_reg(t_carriage *m_carrige, int i_reg);
void			carriages_iterator_set_next(t_itercarr *m_iterator);
void			carriage_set_oper_code(t_carriage *m_crr, t_memory *i_mem);
void			carriage_set_cycle_live(t_carriage *m_carrige, int i_cycle);

/*
** Class Operations
*/

void			operation_exec(t_carriage *m_carriage, t_corewar *m_corewar);
void			operation_fetch_args(t_memory *i_m, int i_addr, t_code *m_code);
t_boolean		operation_valid_code_type_arg(t_code *m_code);
t_boolean		operation_valid_code_oper(int i_code);

int				operation_live(t_carriage *m_ca, t_code *i_cod, t_corewar *m_c);
int				operation_ld(t_carriage *m_cr, t_code *i_cod, t_corewar *m_cor);
int				operation_st(t_carriage *m_cr, t_code *i_cod, t_corewar *m_cor);
int				operation_add(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_sub(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_and(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_or(t_carriage *m_cr, t_code *i_cod, t_corewar *m_cor);
int				operation_xor(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_zjmp(t_carriage *m_ca, t_code *i_cod, t_corewar *m_c);
int				operation_ldi(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_sti(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_fork(t_carriage *m_ca, t_code *i_cod, t_corewar *m_c);
int				operation_lld(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_lldi(t_carriage *m_ca, t_code *i_cod, t_corewar *m_c);
int				operation_aff(t_carriage *m_c, t_code *i_cod, t_corewar *m_cor);
int				operation_lfork(t_carriage *m_ca, t_code *i_cd, t_corewar *m_c);

int				operation_get_cyle_exec(int i_oper_code);

/*
** Class Network
*/
t_boolean		network_user_verification(int fd_client, t_connect *i_conn);
int				network_verification(char *i_pass, int i_fd_server);
void			*network_take_connections(void *m_connect);
void			*network_stop_conections(void *m_connect);
void			*network_recv_players(void *m_connect);
void			*network_broadcast(void *m_connect);
void			network_send_player(t_connect *i_connect, t_player *i_player);
void			network_fetch_data_to_buff(t_buff *m_buf, struct pollfd *i_fds);

t_connect		*network_connect_to_server(t_client *i_client);
t_connect		*network_get_connect_clients(t_server *i_serv, t_players *pls);
void			connect_destroy(t_connect **m_connect);

struct addrinfo	*network_get_servinfo(char *i_ip_server, char *i_port);

/*
** 	Class Network
**		|
**		+--	Class Pakege
*/
void			*net_package_put_end(void *m_dst, int i_code_pakege);
void			*net_package_put_header(void *m_dst, int size_cont, int code_p);
void			network_package_free(t_pack_net *m_pakege);
int				network_pack_player(t_player *i_player, t_pack_net *m_pack);
t_player		*network_unpack_player(t_pack_net *i_pakage);

int				net_get_next_pakage(int fd_from, t_pack_net *m_pakage);

t_boolean		network_pakage_get_header(t_net_buff *m_buf, t_pak_header *m_h);
int				network_pakages_realloc_mem(t_net_buff *m_buff, int i_sz_extra);
int				network_pakage_put_pack_net(t_net_buff *m_buf,
								t_pack_net *m_pakage, t_pak_header *i_header);
int				network_pakage_load_from_net(t_net_buff *m_buff);

/*
** Class Corewar
*/
t_corewar		*new_corewar(t_args_obj *m_args);
t_corewar		*corewar_resolve(t_corewar *m_corewar);
void			destroy_corewar(t_corewar **del_corewar);

void			corewar(int argc, char **argv);
int				corewar_run(t_corewar *m_corewar);
void			corewar_honoring_the_winner(t_corewar *i_corewar);

void			corewar_core(t_corewar *m_corewar);
void			corewar_exec(t_corewar *m_corewar);
void			corewar_check(t_corewar *m_corewar);
void			print_usage(void);
void			print_help(void);

void			corewar_client_mode(t_corewar *m_corewar);
void			corewar_server_mode(t_corewar *m_corewar);
void			corewar_visual_mode(t_corewar *m_corewar);
void			corewar_default_mode(t_corewar *m_corewar);

void			debug_print_memory_fd(int i_fd);

t_boolean		is_suitable_file(char *i_path_to_file);

/*
** Visualization
*/
void			package_init_players(t_players *players, int fd);
void			package_player(t_player *player, int fd);
void			send_package_init_carriages(t_carriages *struct_carriages,
																		int fd);
void			packages_init_corewar(t_corewar *corewar);
void			send_package_new_carriage(t_carriage *carriage, int id_parent,
												int amount_carriages, int fd);
void			package_change_carriage_address(int id, int address, int fd);
void			package_write_in_mem(int mem, int number_byte, int id, int fd);

#endif

/*
** Global variable
*/
typedef struct	s_op
{
	char		name[10];
	int			num_args;
	t_arg_type	type[3];
	int			code;
	int			cycle_to_exec;
	char		description[40];
	t_boolean	have_code_type_arg;
	int			x2;
	int			size_dir;
	int			(*exec)(t_carriage *m_carr, t_code *i_code, t_corewar *m_cor);
}				t_op;

#ifndef GLOBAL
# define GLOBAL

extern t_op				g_op_tab[18];
extern t_arg_type		g_type_tab[2][3];

extern unsigned int		g_options;

#endif
