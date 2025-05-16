NAME= libftprintf.a

CC= gcc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f

SRCS =	ft_putchar.c \
				ft_printf.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_putchar_fd.c \
				ft_printf_ptr.c \
				ft_putnbr.c \
				ft_printf_unsignedint.c \
				ft_printf_hex.c
				
								
OBJS = $(SRCS:.c=.o) 

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS) 

all: $(NAME)

clean:
	@$(RM) $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all