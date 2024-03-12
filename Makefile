##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile my_sokoban
##

SRC	=	src/main.c			\
		src/load_map.c		\
		src/swaps.c			\
		src/move_player.c	\
		src/print_str.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

INCLUDES	=	-Iincludes

LIB	=	-lncurses

$(NAME):
		gcc -o $(NAME) $(SRC) $(INCLUDES) $(LIB) -g

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f a.out

re:		fclean all

.PHONY: all clean fclean re
