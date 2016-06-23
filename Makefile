##
## Makefile for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Fri Feb 26 21:30:18 2016 Baptiste veyssiere
## Last update Thu Jun 23 09:56:57 2016 Baptiste veyssiere
##

NAME	= bin/sudoki-bi

CC	= gcc

RM	= rm -f

DEBUG	= no

ifeq ($(DEBUG), yes)
	CFLAGS	= -W -Werror -Wall -Wextra -ansi -pedantic -I./include -g
else
	CFLAGS	= -W -Werror -Wall -Wextra -ansi -pedantic -I./include
endif

SRCS	= src/sudoki_bi.c	\
	src/get_tab.c		\
	src/free_function.c	\
	src/aff_table.c		\
	src/is_present.c	\
	src/filler.c		\
	src/check_valid.c	\
	src/my_tablen.c		\
	src/my_realloc.c	\
	src/get_list.c		\
	src/sort_list.c		\
	src/get_present.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	mkdir -p bin
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
