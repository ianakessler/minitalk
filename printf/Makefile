	NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_strchr.c \
	   ft_print_str.c \
	   ft_print_number.c \
	   ft_print_char.c \
	   ft_print_hex.c \
	   ft_print_unsigned.c \
	   ft_print_pointer.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
