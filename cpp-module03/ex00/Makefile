NAME		= ClapTrap
CXX			= c++
FILENAME	= file

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	ClapTrap.cpp \
		main.cpp
		
OBJ = $(SRC:.cpp=.o)

all :$(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) $(FILENAME)

re :fclean all

.PHONY:
		all clean fclean re
