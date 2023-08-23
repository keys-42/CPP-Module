NAME		= Sed_is_for_losers
CXX			= c++
FILENAME	= file

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(shell find . -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

all :$(NAME)
	rm -f file
	cat < Makefile  > $(FILENAME)	
	find . -name "*.replace" |xargs rm -f

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) $(FILENAME)
	find . -name "*.replace" |xargs rm -f

re :fclean all

.PHONY:
		all clean fclean re
