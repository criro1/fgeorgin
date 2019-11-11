/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:29:11 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/10/11 17:29:13 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_h
# define PUSH_SWAP_h

# include "stdlib.h"
# include "./ft_printf/include/ft_printf.h"
# include "stdarg.h"

typedef struct          s_arr
{
    int                 n;
    struct s_arr        *next;
}                       t_arr;

long long int	ft_atolli(const char *str);
int				ft_strnbr(int *num, int n, int j);
t_arr			*ft_free(t_arr *head, char **split);
t_arr			*ft_new(char *s, int *num, int j);
void			ft_if_head(t_arr **head, t_arr **tmp, t_arr **p);
t_arr			*ft_nums(t_arr *head, int j, char **av, int *num);
void			ft_push(t_arr **head_into, t_arr **head_out);
void			ft_swap(t_arr **a_head, t_arr **b_head);
void			ft_rotate(t_arr **a_head, t_arr **b_head);
void			ft_reverse_rotate(t_arr **a_head, t_arr **b_head);
void            check_line(char *line, t_arr **src, t_arr **tmp);
t_arr           *ft_checker(t_arr *src);

#endif
