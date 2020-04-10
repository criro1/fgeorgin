#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print_loading.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 20:38:40 by wmaykit           #+#    #+#              #
#    Updated: 2019/12/21 20:38:40 by wmaykit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

printf "\r"
printf "[";
curr=$(cat .all_step | cut -d . -f1)
i=0;
while [ $i -lt 50 ];
do
	if [ $i -lt $curr ];
	then printf "#";
	else printf " ";
	fi;
	i=$[ $i + 1 ];
done

printf "] "
python3 -c "print(int($curr / 50.0 * 100), end = '')"
printf "%% $1"
printf "\e[K"

python3 -c "print($(cat ./.all_step) + $(cat ./.onestep))" > .all_step
