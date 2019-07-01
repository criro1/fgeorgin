# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/01 16:30:19 by fgeorgin          #+#    #+#              #
#    Updated: 2019/07/01 16:57:48 by fgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./ft_open_fillit.c \

HEAD = ./fillit.h

all:
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I$(HEAD)

clean:
	/binrm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
