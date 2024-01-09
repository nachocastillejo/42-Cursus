/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:09:50 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/09 21:03:08 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <stdio.h>*/
#include "libft.h"

int	numlen(int i)
{
	int	mem;

	mem = 0;
	if (i <= 0)
	{
		mem++;
		i = -i;
	}
	while (i >= 1)
	{
		mem++;
		i = i / 10;
	}
	return (mem);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;
	int		mem;

	i = n;
	mem = numlen(i);
	s = (char *)malloc(sizeof(char) * mem + 1);
	if (!s)
		return (NULL);
	s[mem] = '\0';
	mem--;
	j = n;
	if (n < 0)
		j = -n;
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

	my_str = ft_itoa(0);
	printf("%s", my_str);
}*/
