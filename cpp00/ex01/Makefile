NAME = phonebook
CXX = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address

SRC = main.cpp phonebook.cpp contact.cpp
OBJ = $(SRC:.cc=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) $(EXEC)