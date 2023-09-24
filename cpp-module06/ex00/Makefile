NAME	= convert
CXX		= c++

UNAME := $(shell uname)

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

ifneq ($(UNAME), Darwin)
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
endif

SRC =	main.cpp \
		ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

debug: fclean
debug: CXXFLAGS += -g -fsanitize=address
debug: all

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:
	all clean fclean re debug
