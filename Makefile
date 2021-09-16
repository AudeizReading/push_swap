# -----------------------------------------------------------------------------
#                            THINGS TO CHANGE IN THIS MAKEFILE
# -----------------------------------------------------------------------------
# 	-> check les paths des libs (enlever mlx) la libft doit etre a la racine
#   -> check les flags gcc, enlever ce qui concerne la mlx
#   -> modifier les sources
#   -> modifier les rules en conséquences#
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
#                            GCC FLAGS
# -----------------------------------------------------------------------------
CFLAGS=-Wall -Werror -Wextra
CHEADERS= -I ./includes
ALL_FLAGS= $(CHEADERS) $(CFLAGS)
LDFLAGS= -L $(LIBFT_PATH) -lft -L $(GNL_PATH) -lgnl 

# -----------------------------------------------------------------------------
#                            LIBS PATH
# -----------------------------------------------------------------------------
LIBFT_PATH=./libft
GNL_PATH=./lib/gnl

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
	@$(MAKE) gnl
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
#	./$(NAME) maps/13x5_invalid_char.ber
	@$(MAKE) fclean
	
sani: $(OBJ)
	@$(MAKE) libft
	@$(MAKE) gnl
	@$(MAKE) mlx
	cp $(MLX_PATH)/libmlx.dylib .
	@$(ECHO) "$(GRE)"
	$(CC) -g -fsanitize=address -fno-omit-frame-pointer -static-libsan $(LDFLAGS) $^ -o $(NAME) 
	@$(ECHO) "$(NO_COL)"
#	./$(NAME) maps/13x5_valid_map.ber
	./$(NAME) maps/15x15_valid_map.ber
#	./$(NAME) maps/34x6_valid_map.ber
#	./$(NAME) maps/80x25_valid_map.ber
	@$(MAKE) clean
	@$(MAKE) libftclean
	@$(MAKE) gnlclean
	@$(MAKE) mlxclean
	@$(ECHO) "$(RED)"
	$(RM) $(NAME) debug.dSYM libmlx.dylib.dSYM
	@$(ECHO) "$(NO_COL)"

debug: $(OBJ)
	@$(MAKE) libft
	@$(MAKE) gnl
	@$(MAKE) mlx
	cp $(MLX_PATH)/libmlx.dylib .
	@$(ECHO) "$(BLU)"
	$(CC) -g $(LDFLAGS) $^ -o $@
	@$(ECHO) "$(NO_COL)"
	valgrind ./$@ maps/15x15_valid_map.ber
	@$(MAKE) clean
	@$(MAKE) libftclean
	@$(MAKE) gnlclean
	@$(MAKE) mlxclean
	@$(ECHO) "$(RED)"
	$(RM) $@ debug.dSYM
	$(RM) $@ libmlx.dylib.dSYM
	@$(ECHO) "$(NO_COL)"

debug-full: $(OBJ)
	@$(MAKE) libft
	@$(MAKE) gnl
	@$(MAKE) mlx
	cp $(MLX_PATH)/libmlx.dylib .
	@$(ECHO) "$(BLU)"
	$(CC) -g $(LDFLAGS) $^ -o $@
	@$(ECHO) "$(NO_COL)"
	valgrind --leak-check=full --show-leak-kinds=all ./$@ maps/15x15_valid_map.ber
	@$(MAKE) clean
	@$(MAKE) libftclean
	@$(MAKE) gnlclean
	@$(MAKE) mlxclean
	@$(ECHO) "$(RED)"
	$(RM) $@ debug-full.dSYM
	$(RM) $@ libmlx.dylib.dSYM
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

fclean: clean libftclean gnlclean mlxclean
	@$(ECHO) "$(RED)"
	$(RM) $(NAME)
	@$(ECHO) "$(NO_COL)"

fclean-debug: fclean
	@$(ECHO) "$(RED)"
	$(RM) so_long.dSYM
	$(RM) debug debug.dSYM
	$(RM) debug-full debug-full.dSYM
	$(RM) $@ libmlx.dylib $(MLX_PATH)/libmlx.dylib libmlx.dylib.dSYM
	@$(ECHO) "$(NO_COL)"

re: fclean all
