##
## Makefile for RT in /home/david/gtk/menu/version2.0
## 
## Made by david blervaque
## Login   <blerva_d@epitech.net>
## 
## Started on  Tue May 22 09:48:13 2012 david blervaque
## Last update Sat Jun  2 20:19:21 2012 florian dewulf
##

##changer le go_to_config

NAME=		rt_menu

CRE=		create
OB=		objet
CLA=		classique

SRC=		main.c						\
		xopen.c						\
		free_list.c					\
		save_info.c					\
		change_color.c					\
		add_config.c					\
		help_rt_menu.c					\
		xmalloc.c					\
		my_strcmp.c					\
		init_value_info.c				\
		$(CRE)/create_window.c				\
		$(CRE)/create_box.c				\
		$(CRE)/create_menu.c				\
		$(CRE)/create_menu_object.c			\
		$(CRE)/create_menu_about.c			\
		$(CRE)/create_bar.c				\
		$(OB)/pyramid_prism/config_pyramid_prism.c	\
		$(OB)/pyramid_prism/info_pyramid_prism.c	\
		$(OB)/pyramid_prism/color_p.c			\
		$(OB)/$(CLA)/config_classique.c			\
		$(OB)/$(CLA)/create_classique.c			\
		$(OB)/$(CLA)/color.c				\
		$(OB)/$(CLA)/color2.c				\
		$(OB)/$(CLA)/info.c				\
		$(OB)/$(CLA)/go_to_config.c			\
		$(OB)/$(CLA)/func_signal_rotate.c		\
		$(OB)/$(CLA)/func_signal_pos.c			\
		$(OB)/cube/config_cube.c			\
		$(OB)/cube/cube_info.c				\
		$(OB)/cube/color_cube.c				\
		$(OB)/plan/config_plan.c			\
		$(OB)/plan/plan_info.c				\
		$(OB)/plan/color_plan.c				\
		$(OB)/spot/color_spot.c				\
		$(OB)/spot/config_spot.c			\
		file_selection.c				\
		remove_or_hide.c				\
		quit_rt_menu.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		`pkg-config --cflags gtk+-2.0`

LDFLAGS=	`pkg-config --libs gtk+-2.0`

all:		$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		all clean