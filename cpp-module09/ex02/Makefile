.PHONY: all clean fclean re leak address pair separate first insert dclean tidy help

NAME	= PmergeMe
CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

NUMBER =4 18 100 67 71 35 94 89 8 46 78 32 24 1 59 22 13 86 14 80 41 75 44 10 90 88 61 76 34 40
LOGDIR = ./log
MKDIR = mkdir

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all



# debug address leak pair separate first insert
# CXXFLAGS+= -DLISTDEBUG
# CXXFLAGS+= -DVECTORDEBUG
address:fclean
address:CXXFLAGS+= -g -fsanitize=address
address:all

leak:fclean
leak:CXXFLAGS+= -DLEAK
leak:all

pair:fclean
pair:CXXFLAGS+= -DPAIR
pair:all

separate:fclean
separate:CXXFLAGS+= -DSEPARATE
separate:all

first:fclean
first:CXXFLAGS+= -DFIRST
first:all

insert:fclean
insert:CXXFLAGS+= -DINSERT
insert:all

dclean:fclean
	$(RM) -r $(LOGDIR)

# less -R pair.log
debug:
	$(MKDIR) -p $(LOGDIR)
	$(MAKE) pair
	./$(NAME) $(NUMBER) > $(LOGDIR)/pair.log
	$(MAKE) separate
	./$(NAME) $(NUMBER) > $(LOGDIR)/separate.log
	$(MAKE) first
	./$(NAME) $(NUMBER) > $(LOGDIR)/first.log
	$(MAKE) insert
	./$(NAME) $(NUMBER) > $(LOGDIR)/insert.log

tidy:
	clang-tidy $(SRC) -- $(CXXFLAGS) -I./

help:
	@echo "make address"
	@echo "make leak"
	@echo "make pair"
	@echo "make separate"
	@echo "make first"
	@echo "make insert"
	@echo "make debug"

