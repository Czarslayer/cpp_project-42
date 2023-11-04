
Name = ex02

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Fixed.cpp\
	   main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(Name)

$(Name): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(Name)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(Name)

re: fclean all