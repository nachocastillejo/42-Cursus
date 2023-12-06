/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:49:07 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/02 13:49:07 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char *a;

	a = (char*)s;
	i = 0;

	while (i < n)
	{
		if (a[i] == (char)c)
			return (&a[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char my_str[] = "hola";
	
    //printf("%s\n", ft_memchr(my_str, 'o', 4));
	ft_memchr(my_str, 'o', 0);
    // Por qué no me printea ola?
	printf("%s\n",my_str);
}*/
