NAME		= Zombie
CXX			= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Zombie.cpp \
		main.cpp \
		zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

all :$(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re :fclean all

.PHONY:
		all clean fclean re
