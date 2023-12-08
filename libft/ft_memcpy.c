/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:57:39 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/08 21:14:00 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int				i;
	unsigned char				*dest_char;
	unsigned char				*src_char;

	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
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