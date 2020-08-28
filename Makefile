NAME	=	miniRT
INC		=	/usr/include
INCLIB	=	$(INC)/../lib
INCLUDE	=	./Includes/
HT		=	Linux

CFLAGS	=	-I$(INC) -O3 -I$(INCLUDE)

SRC 	=	./srcs/minirt.c ./srcs/ft_init_scene.c
OBJ 	=	$(SRC:.c=.o)

CC		=	gcc
RM		=	/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L./include/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
			$(RM) $(OBJ)

fclean	:
			$(RM) $(NAME) *~ core *.core


re		: 	fclean all
