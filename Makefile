# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 20:24:56 by jsaarine          #+#    #+#              #
#    Updated: 2022/04/24 20:20:50 by jsaarine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
S = src/
SRC =	$Smain.c \
		$Sbackground.c \
		$Sbounds_checks.c \
		$Scolor_maps.c \
		$Scolor.c \
		$Sdraw_map.c \
		$Sdraw.c \
		$Shandle_it.c \
		$Shandle_keys.c \
		$Shelp_text.c \
		$Sinit.c \
		$Sline.c \
		$Sload.c \
		$Spixel_put_color.c \
		$Sprojections.c \
		$Sprojections_more.c \
		$Stransforms.c

HDR = fdf.h fdf_values.h fdf_structs.h
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

mb: $(SRC) $(OBJ) $(LIBA)
	$(CC) -o $@ -I minilibx/ $(SRC) $(LIBA) -L minilibx/ -lmlx -L /usr/X11/lib -l X11 -l Xext $(FRAMEWORKS) -flto -O3
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
