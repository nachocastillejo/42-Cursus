/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:09:10 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/06 13:41:17 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned int		i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (i < len)
	{
		a[i] = c;
		i++;
	}
	return (a);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	my_str[] = "hola";

	ft_memset(my_str, 'c', 4);
	memset(my_str, 'c', 5);
	printf("%s", my_str);
} */