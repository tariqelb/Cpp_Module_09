# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 00:23:02 by tel-bouh          #+#    #+#              #
#    Updated: 2023/04/22 00:23:32 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRCS = ./main.cpp ./RPN.cpp

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
