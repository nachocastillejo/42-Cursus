# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 11:30:29 by igncasti          #+#    #+#              #
#    Updated: 2023/12/08 18:57:29 by igncasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRCS = ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean