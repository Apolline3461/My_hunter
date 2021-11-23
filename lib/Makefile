##
## EPITECH PROJECT, 2021
## Hunter
## File description:
## Makefile
##


SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:		fclean all
