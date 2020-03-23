/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:12:47 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/25 19:07:53 by ediego           ###   ########.fr       */
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
	int					weight;
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
	// int					flag_double;
	// t_link				in_rooms;
	// t_link				out_rooms;
	int					level;
	int					x;
	int					y;
	int					status;
	char				*name_ant;
	int					ind_out_room;
	//=====ediego part============
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
	int					room_in;
	int					room_out;
	//======ediego part==========
	int					sum_r;
	int					sum_d;
	int					tmp;
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
void					ft_do_tmp(t_link **fin, t_link **tmp,
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
int						*ft_ret_way(int **way, t_room curr_room, int min);
void					ft_if_rs_w(int **room_struct, int **way,
							t_room curr_room, int min);
// int						*ft_bfs(t_map *map, t_room curr_r,
// 							t_room prev_r, int min);
int						*ft_bfs(t_map *map, t_room *iter, int next_ind);
/*
**ft_do_ways_diff
*/
int						ft_num_of_links(t_map *map, int num_of_room);
int						ft_output_into_bfs(t_map *map, int ants,
							int *way, int room);
t_w_and_d				*ft_do_ways_diff(t_map *map, t_map *sh_w);
/*
**ft_free_and_malloc.c
*/
void					ft_free_fin(t_link **fin, int diff_len, int *room);
void					ft_free_st(t_w_and_d *st);
t_map					*ft_copy_map(t_map *map);
int						*ft_malloc_roooms(int j);
void					ft_output_lines(t_str *str);
/*
**ft_if_n_ways.c
*/
int						ft_way_n_wout(int *way, int *wout);
void					ret_1_2(t_map *map, t_map *sh_w);
void					ft_del_links(t_map *map, int from, int what);
void					ft_del_1_2(t_map *map, int *way, int *wout);
void					ft_if_n_ways(t_map *map, t_map *sh_w, t_map *tmp);
/*
**ft_move_sh_w.c
*/
void					ft_way_minus(t_map *map, int *way);
void					ft_sort_weight(t_map *map, int *way);
void					ft_move_sh_w_1(t_map *map, t_map *sh_w,
							int *way, int i);
void					ft_move_sh_w_2(t_map *map, t_map *sh_w,
							int *way, int i);
void					ft_move_sh_w_3(t_map *map, t_map *sh_w,
							int *way, int i);
void					ft_move_sh_w(t_map *map, t_map *sh_w, int *way);
/*
**main.c
*/
int						ft_bef(t_w_and_d *var, int j);
void					ft_free_head(t_str *head);
void					ft_exit(t_map *map, char *line, int err);
void					ft_solution(t_map *map);
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
void					ft_sharp(t_map *map, char **line, int *i, int fd);
void					the_links(t_map *map, char *line);
void					the_room(t_map *map, char *line, int sea, int *i);
void					ft_valid(t_map *map, int i);
/*
**ediego part
*/
void		ft_suurballe(t_map *map, int *way);
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
void					vs_sharp(t_map *map, char **line, int *i);
void					vs_number_of_ants(t_map *map, char *line);
void					vs_the_room(t_map *map, char *line, int sea, int *i);
void					vs_the_links(t_map *map, char *line);
void					vs_calc_scale_scene(t_vs *vs, int *ddx, int *ddy);
int						ft_bfs_print(t_map *map, t_room *iter, int next_ind); // delete this!
void					ft_print_map(t_map *map);
long long				vs_atolli(const char *str);
int						vs_num_of_digit(char *s);
int						vs_check_x_y(char *s);
void					vs_free_split(char **arr);
int			vs_find_num(t_room *room, char *arr_n);
void		vs_make_link(t_map *map, int n0, int n1);
int			vs_if_l(t_map *map, int n0, int n1);
int			vs_coord(t_map *map, char *s1, char *s2);
void 		ft_print_way(t_map *map, int *way);
void		vs_exit(t_map *map, char *line, int err);
int			*ft_belford(t_map *map, t_room *iter, int next_ind);

#endif
