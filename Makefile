# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 20:24:56 by jsaarine          #+#    #+#              #
#    Updated: 2022/04/13 17:19:43 by jsaarine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
S = src/
SRC =	$Smain.c \
		$Sload.c \
		$Sdraw.c \
		$Sdraw_map.c \
		$Stransforms.c \
		$Sprojections.c \
		$Sbackground.c \
		$Sline.c \
		$Spixel_put_color.c \
		$Shelp_text.c \
		$Sinit.c \
		$Shandle_it.c



HDR = fdf.h
OBJ = $(SRC:%.c=%.o)
LIBFT = libft/
LIBA = libft/libft.a
FRAMEWORKS = -framework OpenGL -framework AppKit
CC = clang
CFLAGS = #-Wall -Wextra -Werror
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(LIBA)
	$(CC) -o $@ -I /usr/local/include $(SRC) $(LIBA) -L /usr/local/lib/ -lmlx $(FRAMEWORKS) -O3 -flto

mb: $(SRC) $(OBJ) $(LIBA)
	$(CC) -o $@ -I minilibx/ $(SRC) $(LIBA) -L minilibx/ -lmlx -L /usr/X11/lib -l X11 -l Xext $(FRAMEWORKS) -O3 -flto

# -g -fsanitize=address
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
