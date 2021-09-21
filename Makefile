# -----------------------------------------------------------------------------
#                            THINGS TO CHANGE IN THIS MAKEFILE
# -----------------------------------------------------------------------------
#   -> ajouter les paramètres a push_swap : liste d'int ou une seule chaine
#   d'int
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
#                            COLORS
# -----------------------------------------------------------------------------
RED=\033[1;31m
GRE=\033[1;32m
YEL=\033[1;33m
BLU=\033[1;34m
MAG=\033[1;35m
CYA=\033[1;36m
NO_COL=\033[0m

# -----------------------------------------------------------------------------
#                            COMMANDS
# -----------------------------------------------------------------------------
CC=-gcc
ECHO=-echo
RM=-rm -rf
MAKE=make

# -----------------------------------------------------------------------------
#                            LIBS PATH
# -----------------------------------------------------------------------------
LIBFT_PATH=./libft
GNL_PATH=./gnl

# -----------------------------------------------------------------------------
#                            GCC FLAGS
# -----------------------------------------------------------------------------
CFLAGS=-Wall -Werror -Wextra
CHEADERS= -I ./includes
ALL_FLAGS= $(CHEADERS) $(CFLAGS)
#LDFLAGS= -L $(LIBFT_PATH) -lft -L $(GNL_PATH) -lgnl 
LDFLAGS= -L $(LIBFT_PATH) -lft

# -----------------------------------------------------------------------------
#                            FILES
# -----------------------------------------------------------------------------
SRCS=$(addprefix srcs/, $(addsuffix .c, \
	 main\
	 ))\
	 $(addprefix srcs/ft_, $(addsuffix .c, \
	 errors\
	 ))
OBJ=$(SRCS:.c=.o)
NAME=push_swap

# -----------------------------------------------------------------------------
#                            RULES
# -----------------------------------------------------------------------------
.PHONY: all clean fclean re test debug debug-full libft gnl libftclean gnlclean sani 

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) libft
#	@$(MAKE) gnl
	@$(ECHO) "$(GRE)"
	$(CC) $(LDFLAGS) $^ -o $@
	@$(ECHO) "$(NO_COL)"

libft:
	@$(ECHO) "$(YEL)"
	$(MAKE) -C $(LIBFT_PATH) all
	@$(ECHO) "$(NO_COL)"

gnl:
	@$(ECHO) "$(MAG)"
	$(MAKE) -C $(GNL_PATH) all
	@$(ECHO) "$(NO_COL)"

test: $(NAME)
#	./$(NAME) 
	./$(NAME) 23 -98 0  4 105 105 4
	./$(NAME) 4 4 23 -98 0 105 105 
	./$(NAME) 4 4 23 -98 0  4 105 105 
	./$(NAME) 4 4 23 -98  0 105 105 
	./$(NAME) "4 4 23 -98 0 105 105"
	./$(NAME) "4 4 23 -98 0 4 105 105"
	./$(NAME) "4 23 -98 0 4 105 105"
	./$(NAME) "4 4 23 -98   0 105 105"
	./$(NAME) "23 -98 0 4 105 1054 4"
	./$(NAME) "4 4 23 -98 o 105 105"
	./$(NAME) 4 4 23 -98 o 105 105 
	./$(NAME) "Hello World"
	./$(NAME) 4 8 7 6 2 1 5 3 442
	./$(NAME) "4 4 8 7 6 6 2 1 5 3 3"
	./$(NAME) "4 8 7 6 2 1 -16 5 3 442"
	./$(NAME) 4 4 8 7 6 2 1 5 3 442
	./$(NAME) 4 8 7 6 2 1 1 5 3 442
	./$(NAME) "4 8 7 6 2 1 1 5 3 442"
	./$(NAME) 4 8 7 O 2 1 5 3 442
	./$(NAME) 4 8 7 "O" 2 1 5 3 442
	./$(NAME) 442
	./$(NAME) INT_MIN - 1
	./$(NAME) -2147483648
	./$(NAME) -2147483649
	./$(NAME) 2147483647
	./$(NAME) 2147483648
	./$(NAME) 21474836482147483648
	./$(NAME) 2147483648214748
	./$(NAME) -442
	./$(NAME)
	@$(MAKE) fclean
	
sani: $(OBJ)
	@$(MAKE) libft
#	@$(MAKE) gnl
	@$(ECHO) "$(GRE)"
	$(CC) -g -fsanitize=address -fno-omit-frame-pointer -static-libsan $(LDFLAGS) $^ -o $(NAME) 
	@$(ECHO) "$(NO_COL)"
	./$(NAME) 4 4 23 -98 0 105 105 
	./$(NAME) "4 4 23 -98 0 105 105"
	./$(NAME) "4 4 23 -98   0 105 105"
	./$(NAME) "4 4 23 -98 o 105 105"
	./$(NAME) 4 4 23 -98 o 105 105 
	./$(NAME) "Hello World"
	./$(NAME) 4 8 7 6 2 1 5 3 442
	./$(NAME) "4 4 8 7 6 6 2 1 5 3 3"
	./$(NAME) "4 8 7 6 2 1 -16 5 3 442"
	./$(NAME) 4 4 8 7 6 2 1 5 3 442
	./$(NAME) 4 8 7 6 2 1 1 5 3 442
	./$(NAME) "4 8 7 6 2 1 1 5 3 442"
	./$(NAME) 4 8 7 O 2 1 5 3 442
	./$(NAME) 4 8 7 "O" 2 1 5 3 442
	./$(NAME) 442
	./$(NAME) -442
	./$(NAME)
#	./$(NAME) 
#	@$(MAKE) clean
#	@$(MAKE) libftclean
#	@$(MAKE) gnlclean
	@$(MAKE) fclean-debug
	@$(ECHO) "$(RED)"
	@$(ECHO) "$(NO_COL)"

debug: $(OBJ)
	@$(MAKE) libft
#	@$(MAKE) gnl
	@$(ECHO) "$(BLU)"
	$(CC) -g $(LDFLAGS) $^ -o $(NAME)
	@$(ECHO) "$(NO_COL)"
	valgrind ./$(NAME)
	valgrind ./$(NAME) 4 4 23 -98 0 105 105 
	valgrind ./$(NAME) "4 4 23 -98 0 105 105"
	valgrind ./$(NAME) "4 4 23 -98   0 105 105"
	valgrind ./$(NAME) "4 4 23 -98 o 105 105"
	valgrind ./$(NAME) 4 4 23 -98 o 105 105 
	valgrind ./$(NAME) "Hello World"
	valgrind ./$(NAME) 4 8 7 6 2 1 5 3 442
	valgrind ./$(NAME) "4 4 8 7 6 6 2 1 5 3 3"
	valgrind ./$(NAME) "4 8 7 6 2 1 -16 5 3 442"
	valgrind ./$(NAME) 4 4 8 7 6 2 1 5 3 442
	valgrind ./$(NAME) 4 8 7 6 2 1 1 5 3 442
	valgrind ./$(NAME) "4 8 7 6 2 1 1 5 3 442"
	valgrind ./$(NAME) 4 8 7 O 2 1 5 3 442
	valgrind ./$(NAME) 4 8 7 "O" 2 1 5 3 442
	valgrind ./$(NAME) 442
	valgrind ./$(NAME) -442
	valgrind ./$(NAME)
#	@$(MAKE) clean
#	@$(MAKE) libftclean
#	@$(MAKE) gnlclean
	@$(MAKE) fclean-debug
	@$(ECHO) "$(RED)"
	$(RM) $(NAME) debug.dSYM
	@$(ECHO) "$(NO_COL)"

debug-full: $(OBJ)
	@$(MAKE) libft
#	@$(MAKE) gnl
	@$(ECHO) "$(BLU)"
	$(CC) -g $(LDFLAGS) $^ -o $(NAME)
	@$(ECHO) "$(NO_COL)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 4 23 -98 0 105 105 
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "4 4 23 -98 0 105 105"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "4 4 23 -98   0 105 105"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "4 4 23 -98 o 105 105"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 4 23 -98 o 105 105 
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Hello World"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 8 7 6 2 1 5 3 442
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "4 4 8 7 6 6 2 1 5 3 3"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "4 8 7 6 2 1 -16 5 3 442"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 4 8 7 6 2 1 5 3 442
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 8 7 6 2 1 1 5 3 442
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "4 8 7 6 2 1 1 5 3 442"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 8 7 O 2 1 5 3 442
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 8 7 "O" 2 1 5 3 442
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 442
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -442
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
#	@$(MAKE) clean
#	@$(MAKE) libftclean
#	@$(MAKE) gnlclean
	@$(MAKE) fclean-debug
	@$(ECHO) "$(RED)"
	$(RM) $(NAME) debug-full.dSYM 
	@$(ECHO) "$(NO_COL)"

%.o: %.c
	@$(ECHO) "$(GRE)"
	$(CC) $(ALL_FLAGS) -c $< -o $@
	@$(ECHO) "$(NO_COL)"

clean:
	@$(ECHO) "$(RED)"
	$(RM) $(OBJ)
	@$(ECHO) "$(NO_COL)"

libftclean: 
	@$(ECHO) "$(RED)"
	$(RM) $(LIBFT_PATH)/libft.a
	@$(ECHO) "$(NO_COL)"

gnlclean:
	@$(ECHO) "$(RED)"
	$(RM) $(GNL_PATH)/libgnl.a
	@$(ECHO) "$(NO_COL)"

fclean: clean libftclean gnlclean
	@$(ECHO) "$(RED)"
	$(RM) $(NAME)
	@$(ECHO) "$(NO_COL)"

fclean-debug: fclean
	@$(ECHO) "$(RED)"
	$(RM) $(NAME).dSYM
	@$(ECHO) "$(NO_COL)"

re: fclean all
