/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:03:05 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/02 12:03:05 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
