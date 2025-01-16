CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
NAME_SERVER = server
NAME_CLIENT = client

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(OBJ_SERVER) -o $(NAME_SERVER) $(LIBFT)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBFT)

$(OBJ_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -c $(SRC_SERVER) -o $(OBJ_SERVER)

$(OBJ_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -c $(SRC_CLIENT) -o $(OBJ_CLIENT)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C ./libft

re: fclean $(NAME_SERVER) $(NAME_CLIENT)