NAME=libft.a

# Colors ANSI
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
RESET	= \033[0m
PURPLE	= \033[38;5;141m
ORANGE	= \033[38;5;208m
TEAL	= \033[38;5;80m

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
HEADERS = 	-I ./include

LIBFT_SRCS =		./libft/ft_atoi.c \
					./libft/ft_atoll.c \
					./libft/ft_bzero.c \
					./libft/ft_calloc.c \
					./libft/ft_isalnum.c \
					./libft/ft_isalpha.c \
					./libft/ft_isascii.c \
					./libft/ft_isdigit.c \
					./libft/ft_isprint.c \
					./libft/ft_itoa.c \
					./libft/ft_lstadd_back_bonus.c \
					./libft/ft_lstadd_front_bonus.c \
					./libft/ft_lstclear_bonus.c \
					./libft/ft_lstdelone_bonus.c \
					./libft/ft_lstiter_bonus.c \
					./libft/ft_lstlast_bonus.c \
					./libft/ft_lstmap_bonus.c \
					./libft/ft_lstnew_bonus.c \
					./libft/ft_lstsize_bonus.c \
					./libft/ft_memchr.c \
					./libft/ft_memcmp.c \
					./libft/ft_memcpy.c \
					./libft/ft_memmove.c \
					./libft/ft_memset.c \
					./libft/ft_putchar_fd.c \
					./libft/ft_putendl_fd.c \
					./libft/ft_putnbr_fd.c \
					./libft/ft_putstr_fd.c \
					./libft/ft_split.c \
					./libft/ft_strchr.c \
					./libft/ft_strcmp.c \
					./libft/ft_strdup.c \
					./libft/ft_striteri.c \
					./libft/ft_strjoin.c \
					./libft/ft_strlcat.c \
					./libft/ft_strlcpy.c \
					./libft/ft_strlen.c \
					./libft/ft_strmapi.c \
					./libft/ft_strncmp.c \
					./libft/ft_strnstr.c \
					./libft/ft_strrchr.c \
					./libft/ft_strtrim.c \
					./libft/ft_substr.c \
					./libft/ft_tolower.c \
					./libft/ft_toupper.c

FTPRINTF_SRCS =		./ft_printf/ft_printf.c \
					./ft_printf/ft_putnbr_utils.c \
					./ft_printf/ft_put_utils.c

GETNEXTLINE_SRCS =	./get_next_line/get_next_line.c

SRCS = $(LIBFT_SRCS) $(FTPRINTF_SRCS) $(GETNEXTLINE_SRCS)

OBJS = $(SRCS:.c=.o)

all:$(NAME)
	@echo "$(GREEN)✅ Build completed successfully!$(RESET)"

st_msg:
	

$(NAME): $(OBJS)
	@echo "$(PURPLE)📦 Creating the library: $(NAME)"
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@echo "$(CYAN)🛠️  Compiling $@...$(RESET)"
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< 

clean:
	@echo "$(MAGENTA)🗑️🧹Deleting libft .o files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)✅ Done!$(RESET)"

nclean:
	@echo "$(RED)💥 Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✅ Done!$(RESET)"

fclean: clean nclean

re: re_msg fclean all
	
re_msg:
	@echo "$(ORANGE)🔄 Recreating $(NAME)...$(RESET)"

.PHONY: all clean nclean fclean re
