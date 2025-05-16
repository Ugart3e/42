NAME = so_long

# Archivos fuente
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)

# Includes
INCLUDES = -Iinclude -Ilibs/MLX42/include

# Librerías necesarias
LIBMLX42 = libs/MLX42/build/libmlx42.a
LIBS = -Llibs/MLX42/build -lmlx42 $(shell pkg-config --libs glfw3) -ldl -lm \
        -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

# Regla por defecto
all: $(LIBMLX42) $(NAME)

# Compilar el ejecutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Compilar MLX42 si no está ya compilado
$(LIBMLX42):
	@cmake -B libs/MLX42/build -S libs/MLX42 -DMLX42_BUILD_EXAMPLES=OFF
	@cmake --build libs/MLX42/build

# Regla de limpieza
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
