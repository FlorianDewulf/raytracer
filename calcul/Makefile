##
## Makefile for RT in /home/mailli_r//Documents/Igraph/RT
## 
## Made by remi mailliet
## Login   <mailli_r@epitech.net>
## 
## Started on  Tue May 15 15:49:16 2012 remi mailliet
## Last update Sun Jun  3 23:23:13 2012 florian dewulf
##

NAME=	RT

SRC=	concate.c		\
	comp.c			\
	my_puterror.c		\
	convert_to_bmp.c	\
	main.c			\
	func.c			\
	calc.c			\
	trace.c			\
	copy_list.c		\
	rotation.c		\
	matrice.c		\
	inter.c			\
	init_ptr_func.c		\
	lex.c			\
	lex_list.c		\
	print_data_bmp.c	\
	parsing_bmp.c		\
	check_bmp.c		\
	ambiance/ambiance.c	\
	ambiance/lumen.c	\
	ambiance/ombre.c	\
	ambiance/other.c	\
	mov.c			\
	translation.c		\
	prisme.c		\
	pyramide.c		\
	cube.c			\
	multi_thread.c		\
	triangle.c		\
	objet_4e.c		\
	parsing.c		\
	equation_4e.c

OBJ=	$(SRC:.c=.o)

MLX=	-L/usr/X11/lib -lmlx_$(HOSTTYPE) -lXext -lX11

LDFLAGS=	`pkg-config --libs gtk+-2.0`

MATH=	-lm

THREAD=	-lpthread

CFLAGS=	-g -W -Wall `pkg-config --cflags gtk+-2.0` -ggdb3

CC=	gcc

RM=	rm -f

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLX) $(MATH) $(THREAD) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
	$(RM) $(OBJ)