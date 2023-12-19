# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 11:30:29 by igncasti          #+#    #+#              #
#    Updated: 2023/12/19 19:18:36 by igncasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = libft.a # Nombre de la biblioteca estática que se va a crear
CC = gcc # Compilador a utilizar
FLAGS = -Wall -Wextra -Werror # Opciones de compilación, se habilitan advertencias y se trata cualquier advertencia como un error
RM = rm -f # Comando para eliminar archivos

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

# Lista de archivos fuente en C
SRCS = ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c
# Lista de archivos objeto que se generará a partir de los archivos fuente
OBJS = $(SRCS:.c=.o)
# La regla 'all' es la regla por defecto que se ejecuta al llamar 'make' sin argumentos
all: $(NAME)
# La regla para construir la biblioteca estática. # ar rc - Crea la biblioteca estática. # ranlib - Genera la tabla de contenidos en la biblioteca
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) 
	@ranlib $(NAME)
# Regla para compilar archivos fuente a archivos objeto
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
# Regla para limpiar archivos objeto
clean:
	@$(RM) $(OBJS)
# Regla para eliminar todos los archivos generados y la biblioteca estática
fclean: clean
	@$(RM) $(NAME)
# Regla para reconstruir el proyecto desde cero, es decir, eliminar archivos y volver a ejecutar
re:
	@$(MAKE) fclean
	@$(MAKE) all
# La regla .PHONY indica que 'all' y 'clean' no corresponden a archivos reales y siempre deben ejecutarse
.PHONY: all clean