NAME		= ClapTrap
CXX			= c++
FILENAME	= file

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		main.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

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
