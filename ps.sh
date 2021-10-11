# Don't forget to delete it before defense
#!/bin/bash
#gcc -Wall -Werror -Wextra -g -fsanitize=address -fno-omit-frame-pointer -static-libsan srcs/main.c -L ./libft -lft -I ./includes/ -o push_swap 
ARG=`ruby -e "puts (${1}..${2}).to_a.shuffle.join(' ')"`

if [[ `make fclean && make && ./push_swap $ARG | ./checker_Mac $ARG` ]]
then
	./push_swap $ARG | wc -l
else
	echo "Le monsieur t'a dit que c'était cassé !"
fi
