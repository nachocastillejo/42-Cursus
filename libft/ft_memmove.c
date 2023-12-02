/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:30:31 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/02 11:25:44 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			--i;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void) 
{
    char	origen[20] = "Hola, mundo!";
	char	destino[20] = "Adios";

	ft_memmove(destino, origen, strlen(origen) + 1);
	//memmove(destino, origen, strlen(origen) + 1);
    printf("Destino: %s\n", origen);
}*/