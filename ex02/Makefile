# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 03:05:15 by tel-bouh          #+#    #+#              #
#    Updated: 2023/05/04 19:26:35 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS =  ./main.cpp ./PmergeMe.cpp ./SortVector.cpp ./SortDeque.cpp

FLAGS = -Werror -Wextra -Wall -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	c++ $(FLAG) $(SRCS) -o $(NAME)

.cpp.o:
	c++ -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
