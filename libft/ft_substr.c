/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:35:43 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/19 19:35:43 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*ss;
	size_t				size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	else if (size - start < len)
		len = size - start;
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (0);
	i = -1;
	while (++i < len)
		ss[i] = s[i + start];
	ss[i] = '\0';
	return (ss);
}
