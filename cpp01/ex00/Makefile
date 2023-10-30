# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 20:11:25 by mabahani          #+#    #+#              #
#    Updated: 2023/10/24 12:23:06 by mabahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ex00

SRCS = main.cpp \
		newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp

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