/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:24:40 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/08 19:09:49 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		found_start;
	int		found_end;
	char	*trim;

	found_start = 0;
	found_end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[found_start]) && s1[found_start])
		found_start++;
	if (found_end >= 0)
	{
		while (ft_strchr(set, s1[found_end]))
			found_end--;
	}
	trim = ft_substr(s1, found_start, found_end - found_start + 1);
	return (trim);
}
