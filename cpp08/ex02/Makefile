Name = MutantStack

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(Name)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all
