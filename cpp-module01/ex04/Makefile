NAME		= Sed_is_for_losers
CXX			= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(shell find . -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

all :$(NAME)
	rm -f file
	cat < Makefile  > file	
	find . -name "*.replace" |xargs rm -f

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re :fclean all

.PHONY:
		all clean fclean re
