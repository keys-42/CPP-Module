NAME	= PmergeMe
CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRC =	main.cpp \
		PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

ifdef PAIR
CXXFLAGS += -DPAIR
endif

ifdef SEPARATE
CXXFLAGS += -DSEPARATE 
endif

ifdef INSERTATTHESTART
CXXFLAGS += -DINSERTATTHESTART
endif

ifdef SORT
CXXFLAGS += -DSORT
endif

debug:fclean
	make PAIR=1 SEPARATE=1 INSERTATTHESTART=1

pair:fclean
	make PAIR=1
 
separate:fclean
	make SEPARATE=1

first:fclean
	make INSERTATTHESTART=1

sort:fclean
	make SORT=1

help:
	@echo "make debug"
	@echo "make pair"
	@echo "make separate"
	@echo "make first"
	@echo "make sort"
	
