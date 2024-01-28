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

/*
count_words
	1. Aumentamos i hasta que el primer caracter no sea un espacio .
	2. Si i tiene algún caracter, words aumenta 1.
	3. Recorremos el string y:
		a. Si encuentra c y el siguiente caracter no es c ni \0, words aumenta 1.
*/

int	free_memory(char **res, int index)
{
	int	i;

	i = 0;
	if (res[index] == (NULL))
	{
		while (i <= index)
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (1);
	}
	return (0);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i])
		words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}
/*
get_word
	1.Si el separador es nulo, word puede ser como máximo 1. Y en ese caso,
	   retornamos la palabra entera, asignando memoria con strdup
	1. Aumentamos el start point hasta qe no haya c
	2. Sacamos el world len
	3. Restamos al start point el word len (ya que nos había servido de contador)
	4. Asignamos memoria con word_len + 1 para el string que vamos a meter
	5. 
*/

char	*get_word(char *s, int start_point, char c)
{
	char		*str;
	int			word_len;
	int			i;

	if (c == '\0')
		return ((char *)ft_strdup(s));
	word_len = 0;
	i = -1;
	while (s[start_point] == c)
		start_point++;
	while (s[start_point] != c && s[start_point])
	{
		word_len++;
		start_point++;
	}
	start_point = start_point - word_len;
	str = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!str)
		return (NULL);
	while (s[start_point] != c && s[start_point])
		str[++i] = s[start_point++];
	str[i + 1] = '\0';
	return (str);
}
/*
ft_split
	1. Contamos palabras
	2. Reservamos memoria para todas las palabras + 1 (el nulo)
	3. Aumentamos el start_point hasta que el primer caracter no sea c.
	4. Iteramos por cada i de res y asignamos el getword a cada palabra y
		 recalculamos startpoint
*/

char	**ft_split(const char *s, char c)
{
	int			i;
	char		**res;
	int			start_point;

	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = -1;
	start_point = 0;
	while (++i < count_words(s, c))
	{
		res[i] = get_word((char *)s, start_point, c);
		if (free_memory(res, i))
			return (NULL);
		while (s[start_point] == c)
			start_point++;
		start_point = start_point + ft_strlen(res[i]);
	}
	res[i] = NULL;
	return (res);
}
