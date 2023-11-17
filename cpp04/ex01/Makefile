Name = Animal

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(Name)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(Name)

re: fclean all