/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 22:00:14 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/03/20 22:22:06 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_expand_str(char *string, char *buf);
char	*ft_create_arr(char *buf);
char	*ft_create_num(char *buf, int line, int sym, char *str);
char	*ft_fill_str(char *buf, char *str, int b);
int		**ft_num(char *buf, int **n, int sym, int b);
char	ft_find_obstacle(char *buf);
int		ft_min(int left, int up, int upleft);
int		**ft_max(int **n, int line, int sym, int b);
char	*ft_xxx(char *buf, int **n, int line, char *str);
char	ft_find_empty(char *buf);

#endif
