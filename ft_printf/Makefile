# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 20:38:52 by igncasti          #+#    #+#              #
#    Updated: 2024/01/31 21:28:25 by igncasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c
OBJS = $(SRCS:.c=.o) 
all: $(NAME)
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) 
	@ranlib $(NAME)
.c.o:
	@$(CC) $(FLAGS) -c $< -I ./ -o $@
clean:
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)
re:
	@$(MAKE) fclean
	@$(MAKE) all
.PHONY: all clean fclean re