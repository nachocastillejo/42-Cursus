/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:30:31 by igncasti          #+#    #+#             */
/*   Updated: 2023/11/29 22:54:57 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
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

int	main(void) 
{
    char	origen[20] = "Hola, mundo!";
	char	destino[20];

	ft_memmove(origen, origen + 7, 6);
	// memmove(destino, origen, strlen(origen) + 1);
    printf("Destino: %s\n", destino);
}
