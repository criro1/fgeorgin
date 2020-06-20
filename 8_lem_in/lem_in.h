/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:12:47 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/08 15:27:02 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include "mlx.h"
# define YE 0xFFD700
# define RD 0xFF4500
# define FL 0x483D8B
# define GR 0x778899
# define WH 0xF0FFF0
# define BK 0x2B2B3B

typedef struct			s_link
{
	int					link_num;
	struct s_link		*next;
}						t_link;

typedef struct			s_str
{
	char				*line;
	struct s_str		*next;
}						t_str;

typedef struct			s_room
{
	int					num;
	char				*name;
	t_link				*links;
	int					x;
	int					y;
	int					status;
	char				*name_ant;
	int					ind_out_room;
	int					visited;
	int					dup;
}						t_room;

typedef struct			s_w_and_d
{
	int					**ways;
	int					*diff;
	int					diff_len;
	int					res;
	int					num;
	int					v;
}						t_w_and_d;

typedef struct			s_map
{
	t_room				room[1000000];
	int					data;
	int					num_ants;
	t_str				*out;
	t_str				*head;
	int					start;
	char				ok_s;
	int					end;
	char				ok_e;
	int					min;
	int					sum_r;
	int					sum_d;
	int					tmp;
	int					*queue;
	int					*parent;
}						t_map;

typedef struct			s_vs
{
	t_map				*map;
	void				*win;
	void				*ptr;
	float				dx;
	float				dy;
	float				x;
	float				y;
	float				scale;
	int					minx;
	int					miny;
	int					r;
	float				xx;
	float				yy;
	int					max_ant;
}						t_vs;

/*
**ft_ants_to_ways.c
*/
void					ft_do_tmp_1(t_link **fin, t_link **tmp,
							t_w_and_d *st, int stat);
void					ft_output(t_map *map, t_link *fin_j,
							int room, int *way);
void					ft_print_ants(t_map *map, t_link **fin,
							t_w_and_d *st, int *room);
void					ft_add_ant(t_link **fin_j, int ant);
void					ft_ants_to_ways(t_map *map, t_w_and_d *st);
/*
**ft_bfs.c
*/
int						*ft_bfs(t_map *map, t_room *iter, int next_ind);
/*
**ft_del_links.c
*/
void					ft_do_in_move(t_map *map, int *way, int i);
void					ret_1_2(t_map *map, t_map *sh_w);
void					ft_del_links(t_map *map, int from, int what);
/*
**ft_exit_func.c
*/
void					ft_exit(t_map *map, char *line, int err);
void					ft_clear_map(t_map *map);
/*
**ft_finish_sol.c
*/
void					ft_finish_sol(t_map *map, t_w_and_d *var);
/*
**ft_free_and_malloc.c
*/
void					ft_free_fin(t_link **fin, int diff_len, int *room);
void					ft_free_st(t_w_and_d *st);
t_map					*ft_copy_map(t_map *map);
int						*ft_malloc_roooms(int j);
void					ft_output_lines(t_str *str);
/*
**ft_if_cross.c
*/
int						ft_find_crossing(t_map *sh_w, int *way);
void					ft_if_cross(t_map *map, t_map *sh_w,
							t_w_and_d *var, int *way);
/*
**ft_move_sh_w.c
*/
void					ft_move_sh_w(t_map *map, t_map *sh_w, int *way);
/*
**ft_record_way.c
*/
void					ft_record_way(t_w_and_d *var, int i);
/*
**solution_1.c
*/
void					ft_find_res(t_map *map, t_w_and_d *st);
void					ft_finish_move(t_map *map, t_map *sh_w, int *way);
/*
**ft_suurballe_1.c
*/
void					ft_make_dup_link(t_map *map, int *way, int *res);
/*
**ft_suurballe.c
*/
void					ft_suurballe(t_map *map, int *way);
/*
**valid_1.c
*/
long long				ft_atolli(const char *str);
int						ft_num_of_digit(char *s);
int						check_x_y(char *s);
void					ft_free_split(char **arr);
/*
**valid_2.c
*/
int						ft_find_num(t_room *room, char *arr_n);
void					make_link(t_map *map, int n0, int n1);
int						ft_if_l(t_map *map, int n0, int n1);
int						ft_coord(t_map *map, char *s1, char *s2);
/*
**validation.c
*/
void					number_of_ants(t_map *map, char *line);
void					ft_sharp(t_map *map, char **line, int *i);
void					the_links(t_map *map, char *line);
void					the_room(t_map *map, char *line, int sea, int *i);
void					ft_valid(t_map *map, int i);
/*
**visual
*/
void					vs_scene(t_vs *vs);
void					vs_circle(t_vs *vs, int i, int r);
int						vs_x(t_vs *vs, int x);
int						vs_y(t_vs *vs, int y);
void					vs_ant_start(t_vs *vs, t_room *cur);
void					vs_ant_out(t_vs *vs, int i);
void					vs_background(t_vs *vs);
void					vs_scale_scene(t_vs *vs);
int						key_press(int key, t_vs *vs);
int						vs_read_command(t_vs *vs, t_room *cur);
int						close1(t_vs *vs);
void					vs_sharp(t_vs *vs, char **line, int *i);
void					vs_number_of_ants(t_vs *vs, char *line);
void					vs_the_room(t_vs *vs, char *line, int sea, int *i);
void					vs_the_links(t_vs *vs, char *line);
void					vs_calc_scale_scene(t_vs *vs, int *ddx, int *ddy);
void					ft_print_map(t_map *map);
long long				vs_atolli(const char *str);
int						vs_num_of_digit(char *s);
int						vs_check_x_y(char *s);
void					vs_free_split(char **arr);
int						vs_find_num(t_room *room, char *arr_n);
void					vs_make_link(t_map *map, int n0, int n1);
int						vs_if_l(t_map *map, int n0, int n1);
int						vs_coord(t_map *map, char *s1, char *s2);
void					ft_print_way(t_map *map, int *way);
void					vs_exit(t_vs *vs, char *line, int err);

#endif
