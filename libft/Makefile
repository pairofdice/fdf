# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 12:23:08 by jsaarine          #+#    #+#              #
#    Updated: 2022/04/25 00:16:36 by jsaarine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c	\
		ft_memmove.c	ft_memchr.c		ft_memcmp.c		ft_strlen.c		\
		ft_strdup.c		ft_strcpy.c		ft_strncpy.c	ft_strcat.c		\
		ft_strncat.c	ft_strlcat.c	ft_strchr.c		ft_strrchr.c	\
		ft_strnchr.c	ft_strstr.c		ft_strnstr.c	ft_strcmp.c		\
		ft_strncmp.c	ft_atoi.c		ft_isalpha.c	ft_isdigit.c	\
		ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_tolower.c	\
		ft_toupper.c	\
		\
		ft_memalloc.c	ft_memdel.c		ft_strnew.c		ft_strdel.c		\
		ft_strclr.c		ft_striter.c	ft_striteri.c	ft_strmap.c		\
		ft_strmapi.c	ft_strequ.c		ft_strnequ.c	ft_strsub.c		\
		ft_strjoin.c	ft_strtrim.c	ft_strsplit.c					\
		ft_itoa.c		ft_putchar.c	ft_putstr.c		ft_putendl.c	\
		ft_putnbr.c		ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c \
		ft_putnbr_fd.c	\
		\
		ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		\
		ft_lstiter.c	ft_lstmap.c		\
		\
		ft_iswhitespace.c	ft_islower.c	ft_isupper.c	ft_wordcount.c	\
		ft_min.c 		ft_max.c		ft_abs.c	\
		\
		vec_new.c		vec_free.c		vec_from.c		vec_resize.c	\
		vec_push.c		vec_append.c	vec_strapp.c	vec_intapp.c	\
		vec_ptrapp.c	vec_get.c	\
		\
		ft_getnextline.c



OBJS = $(SRCS:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -c -I$(HDRS) -O3 -flto
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

agane: re
	make clean
