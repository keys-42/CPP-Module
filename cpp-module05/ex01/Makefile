NAME	= bureaucrat
CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=leak

SRC =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFALGS) $^ -o $@

clean:
		$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:
	all clean fclean re


