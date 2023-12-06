/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:50:34 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/03 11:50:34 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*a1;
	char	*a2;

	a1 = (char*)s1;
	a2 = (char*)s2;

	unsigned int	i;

	i = 0;
	while ((a1[i] || a2[i]) && i < n)
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}