# Don't forget to delete it before defense
#!/bin/bash
make -C ./libft all
gcc -g -fsanitize=address -fno-omit-frame-pointer -static-libsan srcs/main.c -L ./libft -lft -I ./includes/ -o push_swap 
#make
./push_swap "Hello World"
./push_swap 4 8 7 6 2 1 5 3 442
./push_swap "4 4 8 7 6 6 2 1 5 3 3"
./push_swap "4 8 7 6 2 1 -16 5 3 442"
./push_swap 4 4 8 7 6 2 1 5 3 442
./push_swap 4 8 7 6 2 1 1 5 3 442
./push_swap 4 8 7 O 2 1 5 3 442
./push_swap 4 8 7 "O" 2 1 5 3 442
./push_swap 442
./push_swap -442
./push_swap
make fclean
