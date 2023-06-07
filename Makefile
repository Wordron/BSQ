##
## EPITECH PROJECT, 2022
## Makefie
## File description:
## compile BSQ
##

SRC		=	load_2d_arr_from_file.c	\
			find_biggest_square.c	\
			is_square_of_size.c		\
			fs_get_number_from_first_line.c	\
			fs_count_first_line.c	\
			bsq.c 	\
			core_of_bsq.c	\

OBJ    =    $(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) -Llib -lmy

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
