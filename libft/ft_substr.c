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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ss;

	i = 0;
	while (i >= start && i < len)
	{
		ss[i] = s[i];
		i++;
	}
	return (ss);
}


int	main(void)
{
	char	*my_str = "hola"
	printf("%s", ft_substr(my_str, 1, 2))
}