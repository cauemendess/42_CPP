#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g -std=c++98 -I.
RM		=	rm -rf

# Dir and file names
NAME	=	RPN
SRCS	=	main.cpp RPN.cpp 
OBJS	=	$(SRCS:.cpp=.o)
INC		=	$(wildcard *.hpp)


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
%.o: %.cpp $(INC)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

GREEN  = \033[32m
RED    = \033[31m
RESET  = \033[0m

test: all
	@echo "\n===== SUCCESSFUL TESTS ====="
	@echo "$(GREEN)Input: \"3 4 +\"$(RESET)"
	@./$(NAME) "3 4 +"
	@echo "$(GREEN)Input: \"3 4 2 * +\"$(RESET)"
	@./$(NAME) "3 4 2 * +"
	@echo "$(GREEN)Input: \"7 2 - 3 1 + *\"$(RESET)"
	@./$(NAME) "7 2 - 3 1 + *"
	@echo "$(GREEN)Input: \"5 9 +\"$(RESET)"
	@./$(NAME) "5 9 +"
	@echo "$(GREEN)Input: \"6 7 *\"$(RESET)"
	@./$(NAME) "6 7 *"
	@echo "$(GREEN)Input: \"5 1 2 + 4 * + 3 -\"$(RESET)"
	@./$(NAME) "5 1 2 + 4 * + 3 -"
	@echo "$(GREEN)Input: \"3 5 8 * 7 + *\"$(RESET)"
	@./$(NAME) "3 5 8 * 7 + *"
	@echo "$(GREEN)Input: \"4 2 + 3 5 1 - * +\"$(RESET)"
	@./$(NAME) "4 2 + 3 5 1 - * +"
	@echo "$(GREEN)Input: \"8 4 2 - / 3 +\"$(RESET)"
	@./$(NAME) "8 4 2 - / 3 +"
	@echo "$(GREEN)Input: \"1 2 + 3 + 4 +\"$(RESET)"
	@./$(NAME) "1 2 + 3 + 4 +"
	@echo "$(GREEN)Input: \"2 3 * 4 *\"$(RESET)"
	@./$(NAME) "2 3 * 4 *"

	@echo "\n===== ERROR TESTS ====="
	@echo "$(RED)Input: \"10000 10000 *\"$(RESET)"
	@./$(NAME) "10000 10000 *"
	@echo "$(RED)Input: \"10 2 - 3 -\"$(RESET)"
	@./$(NAME) "10 2 - 3 -"
	@echo "$(RED)Input: \"42\"$(RESET)"
	@./$(NAME) "42"
	@echo "$(RED)Input: \"3 +\"$(RESET)"
	@./$(NAME) "3 +"
	@echo "$(RED)Input: \"3 4 + +\"$(RESET)"
	@./$(NAME) "3 4 + +"
	@echo "$(RED)Input: \"1 +\"$(RESET)"
	@./$(NAME) "1 +"
	@echo "$(RED)Input: \"3 4\"$(RESET)"
	@./$(NAME) "3 4"
	@echo "$(RED)Input: \"+ -\"$(RESET)"
	@./$(NAME) "+ -"
	@echo "$(RED)Input: \"3 0 /\"$(RESET)"
	@./$(NAME) "3 0 /"
	@echo "$(RED)Input: \"3 4 & +\"$(RESET)"
	@./$(NAME) "3 4 & +"
	@echo "$(RED)Input: \"4 5 a +\"$(RESET)"
	@./$(NAME) "4 5 a +"
	@echo "$(RED)Input: \"\"$(RESET)"
	@./$(NAME) ""
	@echo "$(RED)Input: \"    \"$(RESET)"
	@./$(NAME) "    "

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
