NAME	= PmergeMe
CXX		= c++

# CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXFLAGS	= -std=c++98

SRC =	main.cpp \
		PmergeMe.cpp

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

debug:
	make PAIR=1 SEPARATE=1 INSERTATTHESTART=1

p:
	make PAIR=1

sep:
	make SEPARATE=1

first:
	make INSERTATTHESTART=1

sort:
	make SORT=1