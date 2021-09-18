# Don't forget to delete it before defense
#!/bin/bash
make
./push_swap "Hello World"
./push_swap 4 8 7 6 2 1 5 3
./push_swap "4 8 7 6 2 1 5 3"
./push_swap 4 4 8 7 6 2 1 5 3
./push_swap 4 8 7 6 2 1 1 5 3
./push_swap 4 8 7 O 2 1 5 3
./push_swap 4 8 7 "O" 2 1 5 3
make fclean
