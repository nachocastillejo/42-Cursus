/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:04 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/03 16:13:30 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	while (i < (int)count)
	{
		ptr_char[i] = 0;
		i++;
	}
	return (ptr);
}
