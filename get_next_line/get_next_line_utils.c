/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:07 by igncasti          #+#    #+#             */
/*   Updated: 2024/05/08 19:24:21 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_storage(char **string)
{
	free(*string);
	*string = NULL;
}

char	*before_new_line(char *s1)
{
	char	*s1_copy;
	int		before_nl;
	int		i;

	before_nl = 0;
	i = 0;
	while (s1[before_nl])
	{
		if (s1[before_nl] == '\n')
			break ;
		before_nl++;
	}
	s1_copy = (char *)malloc(sizeof(char) * (before_nl + 2));
	if (s1_copy == NULL)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		s1_copy[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
		s1_copy[i++] = '\n';
	s1_copy[i] = '\0';
	return (s1_copy);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	s1_copy = (char *)malloc(sizeof(char) * (i + 1));
	if (s1_copy == NULL)
		return (NULL);
	while (s1[j])
	{
		s1_copy[j] = s1[j];
		j++;
	}
	s1_copy[j] = '\0';
	return (s1_copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i + 1]);
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	res = (char *)malloc(sizeof(char) * ((i + j + 1)));
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free_storage((char **)(&s1));
	return (res);
}
