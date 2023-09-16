NAME	= intern
CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC =	ShrubberyCreationForm.cpp \
		main.cpp \
		RobotomyRequestForm.cpp \
		AForm.cpp \
		Bureaucrat.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFALGS) $^ -o $@

clean:
		$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

re:fclean all

.PHONY:
	all clean fclean re


