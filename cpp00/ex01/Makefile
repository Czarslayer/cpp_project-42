NAME = phonebook
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp phonebook.cpp contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all