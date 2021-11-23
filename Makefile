##
## EPITECH PROJECT, 2021
## Hunter
## File description:
## Makefile
##

SRC	=	main.c

NAME	=	my_hunter

WFLAGS	=	-W -Wall -Wextra -Werror -g

LFLAGS	=	-L lib/ -lmy

IFLAGS	=	-I ./include

CSFFLAGS	=	-lcsfml-graphics -lcsfml-system

all:
	make -C ./lib/ all
	gcc $(SRC) -o $(NAME) $(CSFFLAGS) $(WFLAGS) $(LFLAGS) $(IFLAGS)

clean:
	make -C ./lib clean
	rm -f *~ *#

fclean:	clean
	make -C ./lib fclean
	rm -f $(NAME)

re:	fclean all
