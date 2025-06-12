NAME = so_long

# Directorios
SRCDIR = src
LIBFTDIR = libs/libft
MLXDIR = libs/MLX42

# ✅ CORREGIR: Archivos que realmente existen
SRCS = src/main.c src/check_path.c src/map_check.c src/utils.c src/map_utils.c src/create_map.c src/movement.c src/player_utils.c src/window.c
OBJ = $(SRCS:.c=.o)

# Includes
INCLUDES = -Iinclude -I$(MLXDIR)/include -I$(LIBFTDIR)

# Librerías necesarias
LIBMLX42 = $(MLXDIR)/build/libmlx42.a
LIBFT = $(LIBFTDIR)/libft.a

LIBS = $(LIBFT) -L$(MLXDIR)/build -lmlx42 $(shell pkg-config --libs glfw3) \
       -ldl -lm -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo 

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)
LDFLAGS = $(LIBS)

# Regla por defecto
all: $(LIBMLX42) $(LIBFT) $(NAME)

# Compilar archivos .c a .o
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ejecutable (linking sin CFLAGS)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBMLX42) -o $(NAME) $(LDFLAGS)

# Compilar MLX42
$(LIBMLX42):
	cmake -B $(MLXDIR)/build -S $(MLXDIR) -DMLX42_BUILD_EXAMPLES=OFF
	cmake --build $(MLXDIR)/build

# Compilar libft
$(LIBFT):
	make -C $(LIBFTDIR)

# Limpiar objetos
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFTDIR)
	rm -rf $(MLXDIR)/build

re: fclean all

.PHONY: all clean fclean re