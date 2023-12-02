/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:12:27 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/02 13:12:27 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *s, int c)
{
	int	i;

	i = 1;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char my_str[] = "holahola";
	
    printf("%s\n", ft_strrchr(my_str, 'o'));
    //printf("%s\n", strrchr(my_str, 'o'));
}
*/