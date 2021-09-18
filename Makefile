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
	@$(MAKE) fclean
	
sani: $(OBJ)
	@$(MAKE) libft
#	@$(MAKE) gnl
	@$(ECHO) "$(GRE)"
	$(CC) -g -fsanitize=address -fno-omit-frame-pointer -static-libsan $(LDFLAGS) $^ -o $(NAME) 
	@$(ECHO) "$(NO_COL)"
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
