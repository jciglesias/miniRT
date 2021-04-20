#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 12:55:34 by jiglesia          #+#    #+#              #
#    Updated: 2021/04/20 16:06:51 by jiglesia         ###   ########.fr        #
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
DIRMLX		=	./minilibx-linux/
INCMLX		=	./minilibx-linux/


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

SRC			=	minirt.c ft_save_bmp.c ft_free_scene.c
CHECKING	=	check_elements.c check_figures.c ft_check_entry.c suport_check.c
LASERS		=	ft_mallotrix.c ft_camera_to_world.c ft_colorfigure.c ft_intersect_cy.c ft_back_trace.c ft_sphere_normal.c ft_obs.c ft_obstructions.c ft_pl_obst.c
RENDERING	=	ft_start_render.c ft_load_scene.c ft_color_figures.c ft_render_bmp.c ft_sq_to_pl.c
UTILS		=	ft_strerror.c ft_normal.c ft_maxx.c ft_angle.c ft_copy.c ft_t0t1.c ft_adjust_color.c
EVENTS		=	key_win.c ft_rotate.c ft_resize.c
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

$(NAME)	:		ftlib minilibx $(OBJS)
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
				@(cd $(DIRMLX) && $(MAKE) clean)
				@$(ECHO) '> Remove executable'

re		:		fclean all

ftlib	:
				@(cd $(SUB_MAKE) && $(MAKE))

minilibx:
				@(cd $(DIRMLX) && $(MAKE))

apt		:
				@(sudo apt-get install gcc make xorg libxext-dev libbsd-dev)

.PHONY	:		all clean re

-include $(DEPS)
