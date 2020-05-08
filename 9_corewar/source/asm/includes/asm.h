/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:20:31 by cwitting          #+#    #+#             */
/*   Updated: 2020/04/24 19:03:45 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include "libft.h"
# include "libftprintf.h"

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdint.h>

# define COMMENT_CHAR		'#'
# define COMMENT_CHAR_2		';'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define REGISTER_CHAR		'r'

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

# define REG_NUMBER			16

# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define T_REG				1
# define T_DIR				2
# define T_IND				4

/*
** bc - byte counter for each label
*/

typedef struct				s_labels
{
	char					*name;
	unsigned				bc;
	struct s_labels			*next;
}							t_labels;

typedef struct				s_token_node
{
	char					*type;
	char					*content;
	unsigned				label_bc;
	unsigned				line_i;
	int						dir_size;
	int						arg1;
	int						arg2;
	int						arg3;
	struct s_token_node		*next;
}							t_token_node;

/*
**	used only for parse_args
*/

typedef struct				s_pa
{
	char					*right;
	char					*instr;
	int						arg_amount;
	int						arg_max;
	t_token_node			*save;
}							t_pa;

/*
** bc - total byte counter
*/

typedef struct				s_token_list
{
	int						name;
	int						comment;
	t_token_node			*head;
	t_token_node			*end;
	t_labels				*labels_head;
	int						fd;
	unsigned				bc;
}							t_token_list;

typedef enum				e_type
{
	name,
	comment,
	instr,
	reg = 3,
	label,
	dir_label,
	indir_label,
	dir = 7,
	indir = 8
}							t_type;

void						assemble(char *filename);
char						*ft_strnjoin(char const *s1, char const *s2);
void						create_token(t_token_node **token,
								t_token_list *token_list);
void						get_name(char *ptr, t_token_list *token_list,
											char *line, int fd);
void						get_comment(char *ptr, t_token_list *token_list,
											char *line, int fd);
int							check_symb_after_quot_mark(char *line);
int							check_size(char *content, size_t size);
int							check_for_incorr_symb_before(char *start,
								char *end);
void						check_line_beginning(t_token_list *token_list,
								char *line);
void						parse_after_label(char *line,
								t_token_list *token_list);
int							begin_is_instruction(char *line);
void						parse_args(char *ptr, t_token_list *token_list);
int							label_char_correct(char label_char);
void						parser(t_token_list **token_list);
void						ft_exit(t_token_list *token_list, char *error_msg);
void						to_byte_code(t_token_list *token_list,
								char *filename);
int							check_for_incorr_symb_after_dot_name(char *start,
								char *end);
void						clean(t_token_list *token_list);
void						write_register_fd(char *content, int fd);
void						write_indir_label_fd(int label_bc, int fd);
void						write_indirect_fd(char *content, int fd);
void						write_args_types_code_fd(t_token_node *node, int fd,
												unsigned *curr_bc_tmp);
int							write_instruction_code_fd(char *content, int fd);
unsigned					number_reverse_mem(unsigned i_origin_num);
unsigned					get_number_of_args(t_token_node *node);
void						get_bc_from_args(t_token_node *node, unsigned *bc);
char						*ft_strcpy_upto_ptr(char *new,
								char *save, char *dot);
void						assign_value_to_label(t_token_node *node,
								t_labels *labels);
void						write_direct_fd(char *content,
								int fd, int dir_size);
void						write_dir_label_fd(int label_bc,
								int fd, int dir_size);
void						write_comment_fd(t_token_list *tl, int len);
void						write_name_fd(t_token_list *tl, int len);
void						ft_arg_amount_3(t_token_list **token_list,
								int *arg_amount, t_token_node **save);
void						ft_arg_amount_2(t_token_list **token_list, int
								*arg_amount, t_token_node **save, char *instr);
void						ft_arg_amount_1(t_token_list **token_list,
								int *arg_amount, t_token_node **save);
void						create_arg(t_token_list *token_list,
								char *arg_type, char *ptr, char *right);
void						func_label_char(t_pa **pa, char *ptr,
										t_token_list **token_list);
void						func_direct_char(t_pa **pa, char *ptr,
										t_token_list **token_list);
void						func_reg_char(t_pa **pa, char **ptr,
										t_token_list **token_list);
void						ft_if_ptr_label_char(t_token_list **token_list,
								char **right, char *ptr);
void						ft_if_ptr_direct_char(t_token_list **token_list,
								char **right, char *ptr);
void						ft_if_ptr_direct_char_1(t_token_list **token_list,
								char **right, char *ptr);
void						ft_end_of_while_parse_args(t_token_list **token_list
							, int *arg_amount, char **right, int *arg_max);
void						ft_ptr_register_char(char **right, char **ptr,
					t_token_list **token_list);
int							right_number_of_valid_args_1_1(int arg_n,
								t_token_node **token, t_labels *labels);
int							right_number_of_valid_args_1_2(int arg_n,
								t_token_node **token);
int							right_number_of_valid_args_2_1(int arg_n,
								t_token_node **token, t_labels *labels);
int							right_number_of_valid_args_2_2(int arg_n,
								t_token_node **token, t_labels *labels);
int							right_number_of_args_3_1(int arg_n,
								t_token_node **token);
int							right_number_of_args_3_2(int arg_n,
								t_token_node **token, t_labels *labels);
int							right_number_of_args_3_3(int arg_n,
								t_token_node **token, t_labels *labels);
int							right_number_of_args_3_4(int arg_n,
								t_token_node **token, t_labels *labels);
int							arg_is_valid(char *token_type);
int							such_label_exists(t_labels *labels, char *name);
int							register_is_valid(char *content);
char						*ft_strnct_fr(char *s1, const char *s2, size_t n);
char						*ft_strjoin_free(char *s1, char const *s2);
char						*ft_strnjoin_free(char *s1, char const *s2);
int							check_valid_token(t_token_node *token, int code);
int							name_is_correct(char *ptr);
int							comment_is_correct(char *ptr);

#endif
