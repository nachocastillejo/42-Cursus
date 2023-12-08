/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:04 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/08 21:05:53 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*ptr;
	char	*ptr_char;

	ptr = (void *)malloc(count * size);
	ptr_char = (char *)ptr;
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (int)(count * size))
	{
		ptr_char[i] = 0;
		i++;
	}
	return (ptr);
}
