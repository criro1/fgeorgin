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

void			ft_free_head(t_str *head);
void			ft_exit(t_map *map, char *line, int err);
long long		ft_atolli(const char *str);
int				ft_num_of_digit(char *s);
int				check_x_y(char *s);
void			number_of_ants(t_map *map, char *line);
void			ft_free_split(char **arr);
int				ft_find_num(t_room *room, char *arr_n);
void			make_link(t_map *map, int n0, int n1);
int				ft_if_l(t_map *map, int n0, int n1);
void			the_links(t_map *map, char *line);
int				ft_coord(t_map *map, char *s1, char *s2);
void			the_room(t_map *map, char *line, int sea, int *i);
void			ft_sharp(t_map *map, char **line, int fd, int *i);
void			ft_valid(t_map *map, int i);

#endif