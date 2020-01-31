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
	int					curr_link;
	int					x;
	int					y;
}						t_room;

// typedef struct			s_room
// {
// 	char				*name;
// 	char				**links;
// 	int					curr_link;
// 	int					x;
// 	int					y;
// }						t_room;

typedef struct			s_map
{
	t_room				room[1000000];
	int					hash_of_rooms[1000000];
	int					curr_hash;
	int					data;/*0 - nothing 1 - number_of_ants 2 - the_rooms*/
	int					num_ants;
	int					start;
	int					end;
}						t_map;

#endif