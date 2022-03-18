NAME = a.out

SRCS = 	ft_strcpy_test.c ft_atoi_test.c ft_bzero_test.c \
	ft_memccpy_test.c ft_memchr_test.c ft_memcmp_test.c \
	ft_memcpy_test.c ft_memmove_test.c ft_memset_test.c \
	ft_strcat_test.c ft_strdup_test.c ft_strlen_test.c \
	ft_strncmp_test.c ft_strncpy_test.c ft_strncat_test.c \
	ft_strlcat_test.c ft_strchr_test.c ft_strrchr_test.c

HDRS = libft_test.h 

all: $(NAME)

$(NAME): 
	gcc main_test.c $(SRCS) ../libft.a libft_test.h

agane:
	rm a.out
	make all
