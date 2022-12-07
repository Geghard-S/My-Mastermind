all : my_mastermind

my_mastermind: my_mastermind.o
	gcc -Wall -Wextra -Werror -o my_mastermind my_mastermind.o

my_mastermind.o: my_mastermind.c
	gcc -Wall -Wextra -Werror -c my_mastermind.c

clean: 
	rm -f *.o

fclean: clean
	rm -f my_mastermind

re: fclean all