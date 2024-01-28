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

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*a;

	a = (char *)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == (char)c)
			return (&a[i]);
		i++;
	}
	return (0);
}
