NAME        := libft.a
CC          := cc
FLAGS       := -Wall -Wextra -Werror 

# Archivos fuente de libft
LIBFT_SOURCES := ft_atoi.c \
                 ft_bzero.c \
                 ft_calloc.c \
                 ft_isalnum.c \
                 ft_isalpha.c \
                 ft_isascii.c \
                 ft_isdigit.c \
                 ft_isprint.c \
                 ft_memchr.c \
                 ft_memcmp.c \
                 ft_memcpy.c \
                 ft_memmove.c \
                 ft_memset.c \
                 ft_strchr.c \
                 ft_strdup.c \
                 ft_strjoin.c \
                 ft_strlcat.c \
                 ft_strlcpy.c \
                 ft_strlen.c \
                 ft_strncmp.c \
                 ft_strnstr.c \
                 ft_strrchr.c \
                 ft_substr.c \
                 ft_tolower.c \
                 ft_toupper.c \
                 ft_itoa.c \
                 ft_striteri.c \
                 ft_putchar_fd.c \
                 ft_putstr_fd.c \
                 ft_putendl_fd.c \
                 ft_putnbr_fd.c \
                 ft_split.c \
                 ft_strmapi.c \
                 ft_strtrim.c

# Archivos fuente de ft_printf
PRINTF_SOURCES := printf/ft_putchar.c \
                  printf/ft_printf.c \
                  printf/ft_putstr.c \
                  printf/ft_strlen.c \
                  printf/ft_putchar_fd.c \
                  printf/ft_printf_ptr.c \
                  printf/ft_putnbr.c \
                  printf/ft_printf_unsignedint.c \
                  printf/ft_printf_hex.c

# Archivos fuente de get_next_line
GNL_SOURCES := get_next_line.c \
               get_next_line_utils.c

# Todos los archivos fuente
SOURCES := $(LIBFT_SOURCES) $(PRINTF_SOURCES) $(GNL_SOURCES)

# Archivos objeto
OBJECTS := $(SOURCES:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJECTS)
	@ar crs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all