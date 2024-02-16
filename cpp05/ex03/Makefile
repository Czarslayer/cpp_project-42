Name = Bureau

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp\
	ShrubberyCreationForm.cpp RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(Name)

$(Name): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(Name)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(Name)

re: fclean all