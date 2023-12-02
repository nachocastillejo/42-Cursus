/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:33:26 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/02 11:33:26 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;
	unsigned int	dest_size;
	unsigned int	i;
	unsigned int	j;

	src_size = 0;
	while (src[src_size])
		src_size++;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	i = dest_size;
	j = 0;
	while (i < size - 1 && src[j] && size > 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size > 0 && dest_size <= size)
		dest[i] = '\0';
	// Si size es menor de lo que mide dest, logicamente habrá que retornar lo que mide src más lo que mide size.
	if (size <= dest_size)
		return (size + src_size);
	return (src_size + dest_size);
}