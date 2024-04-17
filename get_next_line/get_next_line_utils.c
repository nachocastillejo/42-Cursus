/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:07 by igncasti          #+#    #+#             */
/*   Updated: 2024/04/17 14:11:54 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*before_new_line(char *s1)
{
	char	*s1_copy;
	int		from_nl;
	int		before_nl;
	int		i;

	before_nl = 0;
	i = 0;
	from_nl = 0;
	while (s1[from_nl] == '\n')
		from_nl++;
	//printf("from_nl -> %d\n", from_nl);
	before_nl = from_nl;
	while (s1[before_nl] && s1[before_nl] != '\n')
		before_nl++;
	//printf("before_nl -> %d\n", from_nl);
	s1_copy = (char *)malloc(sizeof(char) * (before_nl - from_nl + 2));
	if (s1_copy == NULL)
		return (NULL);
	while (s1[from_nl] && s1[from_nl] != '\n')
	{
		s1_copy[i] = s1[from_nl];
		i++;
		from_nl++;
	}
	s1_copy[i] = '\n';
	s1_copy[i + 1] = '\0';
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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] == '\n')
		i++;
	//printf("i -> %d\n", i);
	//printf("c -> %c\n", s[i]);
	while (1)
	{
		if (s[i] == (char)c && s[i + 1] != c)
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
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	else
		res = (char *)malloc(sizeof(char) * ((ft_strlen(s1)
						+ ft_strlen(s2) + 1)));
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}
