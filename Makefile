# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboudy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:53:12 by dboudy            #+#    #+#              #
#    Updated: 2016/03/05 19:12:54 by dboudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
GCC = gcc
PATH_SRC = ./
PATH_OBJ = ./obj/
PATH_INC = libft/includes/
CFLAGS = -Wall -Werror -Wextra
FLAGS2 = -lmlx -framework OpenGL -framework AppKit
HEADERS = ./includes/
SRC = main.c hook.c draw_menu.c event.c zoom.c mandelbrot.c\
	  julia.c burnship.c triangle.c tools.c\
	  draw_choose_color.c init_data.c\

OBJS = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

%.o: %.c $(HEADERS)/fractol.h
	gcc $(CFLAGS) -I $(HEADERS) -I $(PATH_INC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft
	$(GCC) -o $(NAME) $(OBJS) -lm -L libft/ -lft $(FLAGS2)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
