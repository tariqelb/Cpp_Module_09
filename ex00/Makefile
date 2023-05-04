# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 00:26:22 by tel-bouh          #+#    #+#              #
#    Updated: 2023/05/04 19:31:22 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRCS = ./main.cpp ./BitcoinExchange.cpp ./Tool.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

.cpp.o:
	c++ -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
