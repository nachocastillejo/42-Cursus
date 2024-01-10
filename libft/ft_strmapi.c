/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:43:23 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/10 19:43:23 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

Me gustaría hacer una prueba con una función como esta pero con dos parámetros

char	next_char(char c)
{
	c = c + 1;
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int 		i;
	
	new_s = (char *)malloc(sizeof(char)*(ft_strlen((char *)s) + 1));
	if (!new_s)
		return (NULL)
	i = 0;
	while (i < ft_strlen(s))
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*
int	main(void)
{
	printf("%s",ft_strmapi("hola",next_char));
}
*/
