# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 20:38:52 by igncasti          #+#    #+#              #
#    Updated: 2024/01/31 19:18:33 by igncasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# El @ hace que las acciones sean silenciosas y no aparezcan mensajes en consola
# El $ te deja acceder al valor de una variable

NAME = libftprintf.a # Nombre de la biblioteca estática
CC = gcc # Compilador que vamos a utilizar
FLAGS = -Wall -Wextra -Werror # Flags a utilizar al compilar
RM = rm -f # Shortcut para eliminar archivos

SRCS = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putnbr_base.c # Fuentes/funciones sobre las que vamos a crear la biblioteca 
OBJS = $(SRCS:.c=.o) # Objetos (todas las fuentes/funciones pasadas a .o)

# Creamos la regla all, que depende de NAME.
# Construimos un archivo de biblioteca estática a partir de archivos de objeto.
# ar crea un archivo de biblioteca estática (libftprintf.a) a partir de los archivos de objeto "$(OBJS)".
# La opción "rc" de "ar" indica crear (r) el archivo si no existe, y actualizar (c) el archivo existente.
# ranlib genera la tabla de contenido en el archivo de biblioteca estática "$(NAME)"
# (Esto es común en sistemas basados en UNIX para mejorar la eficiencia al buscar símbolos en la biblioteca)
all: $(NAME)
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) 
	@ranlib $(NAME)

# Compilamos los archivos fuente C en archivos objeto
.c.o:
	@$(CC) $(FLAGS) -c $< -I ./ -o $@
# Creamos la regla clean, que si la llamas borra los objetos .o
clean:
	@$(RM) $(OBJS)
# Creamos la regla fclean, que depende de clean (ejecuta clean primero) y luego borra la librería .a. 
fclean: clean
	@$(RM) $(NAME)
# Creamos la regla re que al ejecutarla ejecuta fclean y all 
re:
	@$(MAKE) fclean
	@$(MAKE) all