#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 19:19:55 by ciglesia          #+#    #+#              #
#    Updated: 2020/11/08 21:02:21 by user             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	miniRT

#****************** INC *******************#
# General
INC			=	./Includes/

# Libft
SUB_MAKE	=	./libft/
INCFT		=	./libft/
# Lib mlx
DIRMLX		=	/usr/lib/
INCMLX		=	/usr/include/


INCLUDE		=	-I $(INCMLX) -O3 -I $(INCFT) -I $(INC)

INC_LIB		=	-L$(INCFT) -lft -L$(DIRMLX) -lmlx -lXext -lX11 -lm -lbsd


#***************** SRC* *******************#

DIRSRC		=	./src/
DIRCOMP		=	$(DIRSRC)/check/
DIRINTF		=	$(DIRSRC)/rendering/
DIRUTILS	=	$(DIRSRC)/utils/
DIRLOAD		=	$(DIRSRC)/loading/
DIREVENT	=	$(DIRSRC)/events/
DIRLASER	=	$(DIRSRC)/lasers/

SRC			=	minirt.c
CHECKING	=	check_elements.c check_figures.c ft_check_entry.c suport_check.c
RENDERING	=	ft_start_render.c ft_load_scene.c test_scene.c
LASERS		=
UTILS		=	ft_skip.c  ft_strerror.c
EVENTS		=	mouse_win.c key_win.c
LOADING		=	fill_support.c  ft_fill_elements.c  ft_fill_figures.c  ft_fill_scene.c  ft_init_elements2.c  ft_init_elements.c  ft_init_scene.c

SRCS		=	$(SRC) $(CHECKING) $(RENDERING) $(LASERS) $(UTILS) $(EVENTS) $(LOADING)

#***************** DEPS ******************#

DIROBJ		=	./depo/

OAUX		=	$(SRCS:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d)
OBJS		=	$(OAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRSRC)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRCOMP)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRINTF)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRUTILS)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRLOAD)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIREVENT)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRLASER)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		ftlib $(OBJS)
				@$(CC)  $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIB)
				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@(cd $(SUB_MAKE) && $(MAKE) clean)
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
				@$(ECHO) '> Remove executable'

re		:		fclean all

ftlib	:
				@(cd $(SUB_MAKE) && $(MAKE))

.PHONY	:		all clean re

-include $(DEPS)
