# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astamm <astamm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 15:15:48 by mwuckert          #+#    #+#              #
#    Updated: 2020/01/16 09:32:53 by wmaykit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
		ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
		ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strtrim.c \
		ft_strsub.c ft_strlenc.c ft_strsplit.c ft_countwordc.c \
		ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c \
		ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
		ft_lstdelcontent.c ft_twodarraydel.c ft_countchar.c \
		ft_swap_point.c ft_swap.c ft_power.c ft_sqrt.c \
		ft_delelemofarray.c ft_atoi_base.c ft_strchri.c \
		ft_base_len.c get_next_line.c ft_quick_sort.c ft_isspace.c ft_strnlen.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: fclean all re print_comp

all: start_compile $(NAME) end_compile

start_compile:
	@echo '$(SRC)' | grep -o ' '| wc -l | sed 's/      //' > .onestep
	@ARG=$$(printf "$$(cat ./.onestep).0\n"); python -c "print(50 / $$ARG)" > .onestep
	@cat .onestep > .all_step
	@printf "\e[?25l"
	@printf "\e[?7l"

end_compile:
	@printf "\e[?25h"
	@printf "\e[?7h"
	@rm -f .onestep
	@rm -f .all_step

$(NAME): $(OBJECTS) libft.h
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "\r\e[2K"
	@echo "Done compilling $(NAME)!"

%.o : %.c 
	@gcc $(FLAGS) -c $< -I.
	@#printf "["
	@#curr=$$(cat .all_step | cut -d "." -f1); i=0; while [ $$i -lt 50 ] ;\
		do if [ $$i -lt $$curr ]; then printf "#"; else printf " "; fi; i=$$[ $$i + 1 ]; done
	@#printf "]"
	@#printf "\e[K $$(python -c "print($$(cat .all_step | cut -d "." -f1) / 50.0 * 100)")"
	@#printf " %% $<"
	@#printf "\r"
	@#SUMM=$$(printf "$$(cat ./.all_step)"); ONE_STEP=$$(printf "$$(cat ./.onestep)");\
		python -c "print($$SUMM + $$ONE_STEP)" > .all_step
	@sh print_loading.sh $<

clean:
	@HAVE_FILE="$$(ls | grep -E '.*\.o$$' | wc -l | sed 's/ *//')";\
		if [ $$HAVE_FILE -gt "0" ]; then echo "Object file libft deleted!"; fi
	@rm -rf $(OBJECTS)

fclean: clean
	@HAVE_FILE="$$(ls | grep $(NAME) | wc -l | sed 's/ *//')";\
		if [ $$HAVE_FILE -gt "0" ]; then echo "$(NAME) file deleted!"; fi
	@rm -fr $(NAME)

re: fclean all

