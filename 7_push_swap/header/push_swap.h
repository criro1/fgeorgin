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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct			s_arr
{
	int					n;
	struct s_arr		*next;
}						t_arr;

long long				ft_atolli(const char *str);
int						ft_strnbr(int *num, int n, int j);
t_arr					*ft_new(char *s, int *num, int j);
void					ft_if_head(t_arr **head, t_arr **tmp, t_arr **p);
t_arr					*ft_nums(t_arr *head, int j, char **av, int *num);
void					ft_push(t_arr **head_into, t_arr **head_out);
void					ft_swap(t_arr **a_head, t_arr **b_head);
void					ft_rotate(t_arr **a_head, t_arr **b_head);
void					ft_reverse_rotate(t_arr **a_head, t_arr **b_head);
void					check_line(char *line, t_arr **src, t_arr **tmp);
t_arr					*ft_checker(t_arr *src);
int						ft_lstlen(t_arr *stack);
t_arr					*ft_free(t_arr *head, char **split);
void					ft_exit(int i);
int						ft_find_b(t_arr *stack, int n);
int						ft_find_a(t_arr *stack, int curr_b);
t_arr					*ft_do_copy(t_arr *st);
void					ft_find_min(t_arr *a_st, t_arr *b_st,
						int **ar, int j);
int						ft_if_rrr_w(t_arr *a_st, t_arr *b_st, int a, int b);
int						ft_if_rr_w(t_arr *a_st, t_arr *b_st, int a, int b);
int						ft_j_2_w(t_arr *a_st, t_arr *b_st, int a, int b);
int						ft_j_3_w(t_arr *a_st, t_arr *b_st, int a, int b);
int						ft_find_way(t_arr *a_st, t_arr *b_st, int *curr, int j);
void					ft_sorting(t_arr **a_st, t_arr **b_st, int v, int *ar);
int						ft_if_rrr(t_arr **a_st, t_arr **b_st, int *curr, int v);
int						ft_if_rr(t_arr **a_st, t_arr **b_st, int *curr, int v);
int						ft_j_2(t_arr **a_st, t_arr **b_st, int *curr, int v);
int						ft_j_3(t_arr **a_st, t_arr **b_st, int *curr, int v);
int						ft_choose_way(t_arr **a_st, t_arr **b_st,
						int *curr, int j);
void					ft_screw(t_arr **a_st, int min, int v, int i);
void					ft_check_if_correct(t_arr *a_st);
void					ft_state(t_arr *a_st, t_arr *b_st, int v, int clear);
void					three_num_a(t_arr **a_st, t_arr **b_st, int max, int v);
void					push_swap(t_arr **a_st, int max, int min, int v);

#endif
