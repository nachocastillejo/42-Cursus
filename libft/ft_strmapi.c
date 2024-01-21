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
A cada carácter de la string ’s’, aplica la función ’f’ dando como
parámetros el índice de cada carácter dentro de ’s’ y el propio
carácter. Genera una nueva string con el resultado del uso sucesivo de ’f’
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		i;

	new_s = ft_strdup(s);
	if (!new_s)
		return (NULL);
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
