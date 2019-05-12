# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 22:43:45 by fgeorgin          #+#    #+#              #
#    Updated: 2019/03/20 23:19:44 by fgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = ./main.c \
	  ./funtions.c \
	  ./funtions1.c \

HEAD =./head.h

all:
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I$(HEAD)

clean:
	/binrm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
