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

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] == c)
		i++;
	if (s[0] != c && s[0])
		w++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
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
	str = malloc(i + 1);
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

	w = count_words((char *)s, c);
	res = (char **)malloc(sizeof(char *) * w);
	i = 0;
	j = 0;
	while (i < w)
	{
		res[i] = get_word((char *)s, j, c);
		j = j + ft_strlen(res[i]);
		i++;
	}
	return ((char **)res);
}

int	main(void)
{
	char	**res;

	res = ft_split("hola me llamo", ' ');
	printf("%s", res[2]);
}
