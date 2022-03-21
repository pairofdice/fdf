# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 20:24:56 by jsaarine          #+#    #+#              #
#    Updated: 2022/03/21 12:10:16 by jsaarine         ###   ########.fr        #
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

$(NAME): $(OBJ)
	$(CC) -I /usr/local/include $(SRC) -L /usr/local/lib/ -lmlx $(FRAMEWORKS)

	// $(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBA)

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




cc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
