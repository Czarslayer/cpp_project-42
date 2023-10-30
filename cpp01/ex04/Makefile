# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:24:01 by mabahani          #+#    #+#              #
#    Updated: 2023/10/30 15:48:19 by mabahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex04

SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean	
	rm -rf $(NAME)

re: fclean all	

javel: fclean
	rm -rf *.replace