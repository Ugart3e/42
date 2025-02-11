# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 12:54:06 by jougarte          #+#    #+#              #
#    Updated: 2025/02/11 15:32:40 by jougarte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2
MAKE_LIB = ar -rcs

SRCS_DIR = srcs
SRCS = $(wildcard $(SRCS_DIR)/*.c) main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(ARCHIVE)
	$(CC) $(OBJS) -o $(NAME)

$(ARCHIVE): $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(ARCHIVE)

fclean: clean
	rm -f $(NAME)

re: fclean all