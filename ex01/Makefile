NAME = phonebook
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = main.cpp outils.cpp phonebook.cpp contact.cpp
OBJ = $(SRC:.cc=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) $(EXEC)