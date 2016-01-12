##
## Makefile for myls in /home/theis_p/my_ls/
##
## Made by THEIS Paul
## Login   <theis_p@epitech.eu>
##
## Started on  Fri Nov 27 02:52:39 2015 THEIS Paul
## Last update Sun Nov 29 19:03:29 2015 THEIS Paul
##

CC	= cc

RM	= rm -f

CFLAGS	+= -lmy -L./lib/my
CFLAGS	+= -Iinclude -g

SRCS	= src/my_ls.c			\
	  src/my_date.c				\
	  src/my_read.c				\
	  src/my_checkator.c			\
	  src/my_color.c			\
	  src/my_path.c				\
	  src/my_display.c		\
	  src/my_display_l.c	\
	  src/my_sort.c				\
	  src/my_file.c				\
	  src/my_options.c		\
	  src/my_function.c				\
		src/my_memutilis.c	\
		src/my_digit_manager.c

NAME	= my_ls

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	make -C lib/my/src/
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	make clean -C lib/my/src/
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./lib/libmy.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
