/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:12:47 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/12/07 20:12:49 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

typedef struct			s_str
{
	char				*line;
	struct s_str		*next;
}						t_str;

typedef struct			s_link
{
	int					link_num;
	struct s_link		*next;
}						t_link;

typedef struct			s_room
{
	int					num;
	char				*name;
	t_link				*links;
	int					level; // 1 - start; 2 - second level
	int					x;
	int					y;
}						t_room;

typedef struct			s_w_and_d
{
	int					**ways;
	int					*diff;
	int					diff_len;
}						t_w_and_d;

typedef struct			s_map
{
	t_room				room[10000];
	int					data;/*0 - nothing 1 - number_of_ants 2 - the_rooms*/
	int					num_ants;
	t_str				*out;
	t_str				*head;
	int					start;
	char				ok_s;
	int					end;
	char				ok_e;
	int					min;
}						t_map;
/*ft_ants_to_ways.c*/
void			ft_do_tmp(t_link **fin, t_link **tmp, t_w_and_d *st, int stat);
void			ft_output(t_map *map, t_link *fin_j, int room, int *way);
void			ft_print_ants(t_map *map, t_link **fin,
					t_w_and_d *st, int *room);
void			ft_add_ant(t_link **fin_j, int ant);
void			ft_ants_to_ways(t_map *map, t_w_and_d *st);
/*ft_bfs.c*/
int				*ft_ret_way(int **way, t_room curr_room, int min);
void			ft_if_rs_w(int **room_struct, int **way,
					t_room curr_room, int min);
int				*ft_bfs(t_map *map, t_room curr_r, t_room prev_r, int min);
/*ft_do_ways_diff*/
int				ft_num_of_links(t_map *map, int num_of_room);
int				ft_output_into_bfs(t_map *map, int ants, int *way, int room);
t_w_and_d		*ft_do_ways_diff(t_map *map, t_map *sh_w);
/*ft_free_and_malloc.c*/
void			ft_free_fin(t_link **fin, int diff_len, int *room);
void			ft_free_st(t_w_and_d *st);
t_map			*ft_copy_map(t_map *map);
int				*ft_malloc_roooms(int j);
void			ft_output_lines(t_str *str);
/*ft_if_n_ways.c*/
int				ft_way_n_wout(int *way, int *wout);
void			ret_1_2(t_map *map, t_map *sh_w);
void			ft_del_links(t_map *map, int from, int what);
void			ft_del_1_2(t_map *map, int *way, int *wout);
void			ft_if_n_ways(t_map *map, t_map *sh_w, t_map *tmp);
/*ft_move_sh_w.c*/
void			ft_move_sh_w_1(t_map *map, t_map *sh_w, int *way, int i);
void			ft_move_sh_w_2(t_map *map, t_map *sh_w, int *way, int i);
void			ft_move_sh_w_3(t_map *map, t_map *sh_w, int *way, int i);
void			ft_move_sh_w(t_map *map, t_map *sh_w, int *way);
/*main.c*/
void			ft_free_head(t_str *head);
void			ft_exit(t_map *map, char *line, int err);
void			ft_solution(t_map *map, t_room *room);
/*valid_1.c*/
long long		ft_atolli(const char *str);
int				ft_num_of_digit(char *s);
int				check_x_y(char *s);
void			ft_free_split(char **arr);
/*valid_2.c*/
int				ft_find_num(t_room *room, char *arr_n);
void			make_link(t_map *map, int n0, int n1);
int				ft_if_l(t_map *map, int n0, int n1);
int				ft_coord(t_map *map, char *s1, char *s2);
/*validation.c*/
void			number_of_ants(t_map *map, char *line);
void			ft_sharp(t_map *map, char **line, int fd, int *i);
void			the_links(t_map *map, char *line);
void			the_room(t_map *map, char *line, int sea, int *i);
void			ft_valid(t_map *map, int i);

#endif
