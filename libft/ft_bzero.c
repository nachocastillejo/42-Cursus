/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:30:48 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/08 19:39:39 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned int		i;
	char				*a;

	a = (char *)s;
	i = 0;
	while (i < len)
	{
		a[i] = 0;
		i++;
	}
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	my_str[] = "hola";

	ft_bzero(my_str, 16);
	// bzero(my_str, 0);
	printf("%s", my_str);
} */
