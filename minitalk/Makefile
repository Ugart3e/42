CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
NAME_SERVER = server
NAME_CLIENT = client

# Regla principal para compilar el servidor y enlazar con libft.a
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(OBJ_SERVER) -o $(NAME_SERVER) $(LIBFT)

# Regla principal para compilar el cliente y enlazar con libft.a
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBFT)

# Compilar el archivo fuente server.c
$(OBJ_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -c $(SRC_SERVER) -o $(OBJ_SERVER)

# Compilar el archivo fuente client.c
$(OBJ_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -c $(SRC_CLIENT) -o $(OBJ_CLIENT)

# Regenerar libft.a si no existe
$(LIBFT):
	make -C ./libft

# Limpiar archivos intermedios
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	make clean -C ./libft

# Eliminar todo, incluyendo los ejecutables
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C ./libft

# Regenerar todo
re: fclean $(NAME_SERVER) $(NAME_CLIENT)