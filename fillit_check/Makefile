# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnita <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 17:43:11 by pnita             #+#    #+#              #
#    Updated: 2019/04/07 18:30:46 by pnita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRCS=main.c fillit.c fillit1.c fillit2.c
OBJECTS=main.o fillit.o fillit1.o fillit2.o
FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(LIB) $(OBJECTS)
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(LIB)
	/bin/rm -f .DS_Store

$(LIB):
	make -C libft

%.o: %.c fillit.h
	gcc $(FLAGS) -o $@ -c $<

clean:
	/bin/rm -f *.o
	make -C libft clean
	/bin/rm -f .DS_Store

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
	make -C libft re