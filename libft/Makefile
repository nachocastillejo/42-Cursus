# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 11:30:29 by igncasti          #+#    #+#              #
#    Updated: 2024/01/21 22:10:52 by igncasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = libft.a
CC = gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f

SRCS = ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c  ft_strnstr.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strjoin.c ft_substr.c ft_strncmp.c ft_tolower.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c
OBJS = $(SRCS:.c=.o)

BSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BOBJS = $(BSRCS:.c=.o)
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
re:
	@$(MAKE) fclean
	@$(MAKE) all
bonus: $(BOBJS)
	@ar rc $(NAME) $(BOBJS) 
	@ranlib $(NAME)	

.PHONY: all clean fclean re ar bonus