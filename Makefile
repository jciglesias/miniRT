NAME	=	miniRT
DIRSRC	=	./srcs/
DIROBJ	=	./obj/
INC		=	/usr/include
INCLIB	=	$(INC)/../lib
INCLUDE	=	./Includes/

CFLAGS	=	-I$(INC) -O3 -I$(INCLUDE) -Wall -Wextra -Werror

SRC 	=	$(DIRSRC)minirt.c $(DIRSRC)ft_init_scene.c $(DIRSRC)ft_fill_scene.c
OBJ 	=	$(SRC:.c=.o)
OBJS	=	$(OBJ:%=$(DIROBJ)%)

CC		=	gcc
RM		=	/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L./include/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME) *~ core *.core

re		: 	fclean all

.PHONY	:	all clean re

%.o		:	$(DIRSRC)/%.c
			$(CC) $(INCLUDE) $(CFLAGS) -o $(DIROBJ)/$@ -c $<
