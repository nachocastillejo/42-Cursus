/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:14:32 by igncasti          #+#    #+#             */
/*   Updated: 2023/12/21 20:33:15 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim2(char const *s1, char const *set)
{
	int			found_start;
	int			found_end;
	char		*res;

	found_start = 0;
	found_end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[found_start]) && s1[found_start])
		found_start++;
	while (ft_strchr(set, s1[found_end]))
		found_end--;
	res = ft_substr(s1, found_start, found_end - found_start + 1);
	return (res);
}

int	main(void)
{
	printf("%s", ft_strtrim2(" h ola ", " n"));
}