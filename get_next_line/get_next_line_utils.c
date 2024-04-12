/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:07 by igncasti          #+#    #+#             */
/*   Updated: 2024/04/12 19:45:13 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*filter_first_chars(const char *s1, int len)
{
	char	*s1_copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && i < len)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*ss;
	size_t				size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	else if (size - start < len)
		len = size - start;
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (0);
	i = -1;
	while (++i < len)
		ss[i] = s[i + start];
	ss[i] = '\0';
	return (ss);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			--i;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}

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
/*
int	ending_set(char *buf)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (buf[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
int	find_new_line(int fd)
{
	char		buf[256];
	static int	new_line;
	int			i;
	int			ending_set_value;
	int			range;
	int			accum_range;
	int			bytes_read;

	range = 4;
	accum_range = range;
	if (new_line == 0)
		lseek(fd, new_line, SEEK_SET);
	else
		lseek(fd, ++new_line, SEEK_SET);
	printf("new line internal -> %d\n", new_line);
	while ((bytes_read = read(fd, buf, accum_range)))
	{
		printf("bytes_read -> %d\n", bytes_read);
		printf("buffer internal -> %s\n", buf);
		ending_set_value = ending_set(buf);
		printf("ending_set_value internal -> %d\n", ending_set_value);
		if (!ending_set_value)
			buf[accum_range] = '\0';
		i = 0;
		while (buf[i])
		{
			if (buf[i] == 'a')
				return (new_line);
			i++;
			new_line++;
		}
		if (ending_set_value)
			return (0);
		if (bytes_read < range)
			return (0);
		buf[accum_range] = ' ';
		lseek(fd, new_line - accum_range, SEEK_SET);
		new_line = new_line - accum_range;
		accum_range = accum_range + range;
	}
	return (0);
}

*/

/*
int	find_new_line(int fd)
{
	char		buf[256];
	static int	new_line;
	int			i;
	int			ending_set_value;
	int			previous_new_line;
	int			range;
	int			accum_range;

	range = 4;
	accum_range = range;
	previous_new_line = 0;
	if (new_line == 0)
		new_line = 1;
	else
		new_line++;
	new_line --;
	while (read(fd, buf, accum_range))
	{
		ending_set_value = ending_set(buf);
		if (!ending_set_value)
			buf[4] = '\0';
		i = 0;
		while (buf[i])
		{
			if (buf[i] == 'a')
			{
				lseek(fd, new_line - previous_new_line, SEEK_SET);
				return (new_line++);
			}
			i++;
			new_line++;
			previous_new_line++;
		}
		if (ending_set_value)
			break ;
		buf[4] = ' ';
		accum_range = accum_range + range;
		lseek(fd, new_line - previous_new_line, SEEK_SET);
	}
	return (0);
}
*/
