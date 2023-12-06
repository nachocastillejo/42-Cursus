/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:59:25 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/03 11:59:25 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*is_found(const char *str, char *to_find, size_t l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == to_find[j] && i < l)
		{
			k = i;
			while (str[k] == to_find[j])
			{
				j++;
				k++;
				if (to_find[j] == '\0')
					return (str + i);
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	if (needle[0] == '\0')
		return (haystack);
	return (is_found(haystack, needle, l));
}
/*
int	main(void)
{
	char	*res;
	char	*str1;
	char	*str2;

	str1  = "buenos días";
	str2  = "s";
	res = ft_strstr(str1, str2);
	printf("%s", res);	
	printf("%c", '\n');
	res = strstr(str1, str2);
	printf("%s", res);
}*/