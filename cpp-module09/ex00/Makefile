NAME	= btc
CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
DEBUGFLAG=

CXXFLAGS+= $(DEBUGFLAG)

SRC =	main.cpp \
		BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)


all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(DEBUGFLAG) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all

debug:fclean
debug:DEBUGFLAG+= -g -fsanitize=address
debug:all

.PHONY:
	all clean fclean re debug
