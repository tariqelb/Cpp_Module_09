# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 03:05:15 by tel-bouh          #+#    #+#              #
#    Updated: 2023/04/25 03:10:20 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dklsbfsiydgvdsj

SRC =  ./local.cpp

FLAG = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME) :
	c++ $(FLAG) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
