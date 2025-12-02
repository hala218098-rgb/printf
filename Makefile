NAME = libftprintf.a

SRCS = ft_hexadecimal.c \
       ft_pointer.c    \
	   ft_printf.c     \
	   ft_words.c      \
	   ft_digits.c


CFLAGS = -Wall -Werror -Wextra

CC = cc

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all