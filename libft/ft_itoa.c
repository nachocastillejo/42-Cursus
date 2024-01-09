/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:09:50 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/09 21:47:48 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	numlen(long i)
{
	long	mem;

	mem = 1;
	if (i < 0)
	{
		mem++;
		i = -i;
	}
	while (i > 9)
	{
		mem++;
		i = i / 10;
	}
	return (mem);
}

char	*ft_itoa(int n)
{
	char		*s;
	long		i;
	long		j;
	long		mem;

	i = n;
	mem = numlen(i);
	s = (char *)malloc(sizeof(char) * mem + 1);
	if (!s)
		return (NULL);
	s[mem] = '\0';
	mem--;
	j = n;
	if (n < 0)
		j = -i;
	while (mem >= 0)
	{
		s[mem] = (j % 10) + '0';
		j = j / 10;
		mem--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
/*
int	main(void)
{
	char	*my_str;

	my_str = ft_itoa(-2147483648);
	printf("%s", my_str);
}*/
