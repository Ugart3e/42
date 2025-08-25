NAME=minishell

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
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -g
RM = rm -f

LIBFT =		./libs
HEADERS = 	-I ./include -I $(LIBFT)/include
LIBS = 		$(LIBFT)/libft.a -lreadline


SRCS_BUILTIN =			sources/builtin/ft_cd.c \
						sources/builtin/ft_echo.c \
						sources/builtin/ft_env.c \
						sources/builtin/ft_exit.c \
						sources/builtin/ft_export_argv.c \
						sources/builtin/ft_export_utils.c \
						sources/builtin/ft_export.c \
						sources/builtin/ft_pwd.c \
						sources/builtin/ft_unset.c

SRCS_EXECUTOR =			sources/executor/executor_utils.c \
						sources/executor/executor_utils2.c \
						sources/executor/ft_executor.c \
						sources/executor/path_utils.c

SRCS_PARSER = 			sources/parser/expand_variables_utils.c \
						sources/parser/expand_variables.c \
						sources/parser/parse_redirection.c \
						sources/parser/parse_tokens.c \
						sources/parser/parse_utils.c \
						sources/parser/parse_utils_utils.c \
						sources/parser/parser.c \
						sources/parser/tokenize_utils.c \
						sources/parser/tokenize_utils2.c \
                        sources/parser/tokenizer.c

SRCS_UTILS =			sources/utils/ft_free.c \
						sources/utils/ft_free2.c \
						sources/utils/ft_signals.c

SRCS =					sources/minishell.c \
						$(SRCS_BUILTIN) \
						$(SRCS_EXECUTOR) \
						$(SRCS_PARSER) \
						$(SRCS_UTILS)

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)
	@echo "$(GREEN)✅ Build completed successfully!$(RESET)"

libft:
	@if [ ! -f "$(LIBFT)/libft.a" ]; then \
		make -s -C $(LIBFT); \
		make clean -s -C $(LIBFT); \
	fi

%.o: %.c
	@echo "$(CYAN)🛠️  Compiling $@...$(RESET)"
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "$(PURPLE)📦 Creating the program: $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(SANITAZE) -o $(NAME)

clean:
	@echo "$(MAGENTA)🗑️🧹Deleting $(NAME) .o files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)✅ Done!$(RESET)"
	@make nclean -s -C $(LIBFT)

fclean: clean
	@echo "$(RED)💥 Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✅ Done!$(RESET)"

re: re_msg fclean all

new: re_msg fclean all
	@make -s clean

re_msg:
	@echo "$(ORANGE)🔄 Recreating $(NAME)...$(RESET)"

# Reglas de Valgrind para depuración de memoria
valgrind: new
	@echo "$(TEAL)🔍 Running Valgrind with system library suppressions...$(RESET)"
	@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=definite,indirect,possible \
		--suppressions=valgrind.supp --track-origins=yes ./$(NAME)

valgrind-full: new
	@echo "$(TEAL)🔍 Running full Valgrind analysis (including reachable)...$(RESET)"
	@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all \
		--suppressions=valgrind.supp --track-origins=yes ./$(NAME)

valgrind-clean: new
	@echo "$(TEAL)🔍 Running Valgrind showing only your code leaks...$(RESET)"
	@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=definite,indirect \
		--suppressions=valgrind.supp --track-origins=yes ./$(NAME)

valgrind-test: new
	@echo "$(TEAL)🔍 Running Valgrind with test commands...$(RESET)"
	@echo "echo test\nexit" | valgrind --tool=memcheck --leak-check=full \
		--show-leak-kinds=definite,indirect --suppressions=valgrind.supp \
		--track-origins=yes ./$(NAME)

valgrind-debug: new
	@echo "$(TEAL)🔍 Running Valgrind in debug mode (no suppressions)...$(RESET)"
	@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all \
		--track-origins=yes --verbose ./$(NAME)

.PHONY: all libft clean fclean re new valgrind valgrind-full valgrind-clean valgrind-test valgrind-debug
