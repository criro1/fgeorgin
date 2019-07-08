/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:44:13 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/07/08 17:01:27 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_tetr
{
	int		row[4];
	int		col[4];
	char	letter;
}				t_tetr;

int				ft_checkfile(char *ac, t_tetr *mas);
int				ft_istetra(char *buf, int sh);
int				ft_createfig(char *buf, t_tetr *mas);
void			ft_move(t_tetr *res);
char			**ft_solver(t_tetr *lst);
char			**ft_fill_map(char **map, int x, int y, t_tetr *lst);
char			**ft_if_fisrt_ok(char **map, t_tetr *lst, int x, int y);
char			**ft_copy(char **dst, char **src, int len);
char			**ft_insert_fig(char **map, int x, int y, t_tetr current);
int				ft_check_fig(int x, int y, t_tetr fig, char **map);
int				ft_find_lst(char **map, int size);
size_t			ft_first_approx(t_tetr *mas);
char			**ft_create_map(size_t size);
void			ft_destroy_map(char **map, int len);
void			ft_print_map(char **map);

#endif
