Name = Animal

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(Name)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(Name)

re: fclean all