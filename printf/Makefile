# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljessica <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 14:07:06 by ljessica          #+#    #+#              #
#    Updated: 2025/04/23 15:05:06 by ljessica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name

NAME = libftprintf.a
EXEC = a.out

SRCS = ft_hex.c ft_int.c ft_printf.c 
OBJS = $(SRCS:.c=.o)

# Compiler

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Commands

AR = ar -rcs
RM = rm -fr

# Rules

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

$(OBJS):%.o: %.c
	$(CC) $(CFLAGS) $< -c

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC)
	
re: fclean all

.PHONY: all clean fclean re
