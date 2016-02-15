# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboudy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:53:12 by dboudy            #+#    #+#              #
#    Updated: 2016/02/15 18:39:46 by dboudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
GCC = gcc
PATH_SRC = ./
PATH_OBJ = ./obj/
PATH_INC = libft/includes/
CFLAGS = -Ofast -Wall -Werror -Wextra
FLAGS2 = -lmlx -framework OpenGL -framework AppKit
HEADERS = ./includes/
SRC = main.c bres.c bres_paint.c bres_del.c draw_cercle.c\

OBJS = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all:$(NAME)

$(OBJS):
	$(GCC) $(CFLAGS) -I $(HEADERS) -I $(PATH_INC) -c $(SRC)

$(NAME):$(OBJS)
	make -C libft
	$(GCC) -o $(NAME) $(OBJS) -lm -L libft/ -lft $(FLAGS2)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
