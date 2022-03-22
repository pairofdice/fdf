# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 20:24:56 by jsaarine          #+#    #+#              #
#    Updated: 2022/03/22 13:23:52 by jsaarine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
S = src/
SRC = $Smain.c
HDR = fdf.h
OBJ = $(SRC:%.c=%.o)
LIBFT = libft/
LIBA = libft/libft.a
FRAMEWORKS = -framework OpenGL -framework AppKit
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(LIBA)
	$(CC) -o $@ -I /usr/local/include $(SRC) $(LIBA) -L /usr/local/lib/ -lmlx $(FRAMEWORKS)

$(LIBA):
	make -C $(LIBFT)

%.o: %.c $(LIBA) $(HDR)
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
