/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:57:10 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/13 12:57:10 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_words(const char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (!s)
		return (0);
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[0] != c && s[0])
		w++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			w++;
		if (s[0] == c && s[i + 1] == '\0')
			w++;
		i++;
	}
	return (w);
}

char	*get_word(char *s, int j, char c)
{
	char		*str;
	int			i;
	int			k;
	int			l;

	i = 0;
	k = j - 1;
	l = 0;
	while (s[++k] == c)
		j++;
	while (s[k] != c && s[k])
	{
		i++;
		k++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (s[j] != c && s[j])
	{
		str[l] = s[j];
		l++;
		j++;
	}
	str[l] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int			w;
	int			i;
	char		**res;
	int			j;
	int			n;

	n = 0;
	if (c == '\0')
		n = 1;
	i = 0;
	if (!s)
		return (0);
	w = count_words((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (w + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s && s[j] == c && s[j + 1])
		j++;
	while (i < w)
	{
		if (n == 1)
		{
			res[i] = (char *)ft_strdup(s);
			i++;
		}
		else
		{
			res[i] = get_word((char *)s, j, c);
			while (s[j] == c)
				j++;
			j = j + ft_strlen(res[i]);
			i++;
		}
	}
	res[i] = NULL;
	return ((char **)res);
}
/*
int	main(void)
{
	char	**res;

    res = ft_split("ytfyft", '\0');
	printf("%s", res[0]);
}
*/