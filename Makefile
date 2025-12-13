CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_PATH = ./lib
LIBFT_A = $(LIBFT_PATH)/libft.a

PRINTF_PATH = ./printf
PRINTF_A = $(PRINTF_PATH)/libftprintf.a


INCLUDES = -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I.

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all:	$(LIBFT_A) $(SERVER) $(CLIENT) $(PRINTF_A)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_PATH)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CLIENT): $(CLIENT_OBJ) $(LIBFT_A) $(PRINTF_A)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(LIBFT_A) $(PRINTF_A)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(SERVER)

clean:
	@make clean -C $(PRINTF_PATH)
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean:	clean
	@make fclean -C $(PRINTF_PATH)
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
