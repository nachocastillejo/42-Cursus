/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:57:39 by igncasti          #+#    #+#             */
/*   Updated: 2023/11/29 22:29:56 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*dest_char;
	char	*src_char;

	dest_char = (char *)dest;
	src_char = (char *)src;
	i = 0;
	while (src_char[i])
	{
		dest_char[i] = src_char[i];
		i++;
	}
	dest_char[i] = '\0';
	return (dest_char);
}

/* 
#include <stdio.h>
#include <string.h>

int	main(void) 
{
    char	origen[] = "Hola, mundo!";
	char	destino[20];

	ft_memcpy(destino, origen, strlen(origen) + 1);
	// memcpy(destino, origen, strlen(origen) + 1);
    printf("Destino: %s\n", destino);
}*/