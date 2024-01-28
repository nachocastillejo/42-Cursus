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

#include "libft.h"

char	*is_found(const char *str, const char *to_find, size_t l)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == to_find[j] && i < l)
		{
			k = i;
			while (str[k] == to_find[j] && k < l)
			{
				j++;
				k++;
				if (to_find[j] == '\0')
					return ((char *)str + i);
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
		return ((char *)haystack);
	return (is_found(haystack, needle, l));
}
