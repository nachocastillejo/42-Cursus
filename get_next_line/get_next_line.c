/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:06:18 by igncasti          #+#    #+#             */
/*   Updated: 2024/04/15 11:52:59 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*before_new_line(char *s1)
{
	char	*s1_copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	s1_copy = (char *)malloc(sizeof(char) * (i + 1));
	if (s1_copy == NULL)
		return (NULL);
	while (s1[j] && j < i)
	{
		s1_copy[j] = s1[j];
		j++;
	}
	s1_copy[j] = '\0';
	return (s1_copy);
}
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			chars_read;
	char		*temp;
	char		*res;
	static char	*static_text;
	int			i;

	if (static_text != 0)
	{
		printf("STATIC TEXT PRE 1 -> %s\n", static_text);
		i = 0;
		while (static_text[i])
		{
			if (static_text[i] == '\n')
			{
				res = before_new_line(static_text);
				printf("res PRE -> %s\n", res);
				temp = ft_strchr(static_text, '\n');
				printf("temp PRE -> %s\n", temp);
				free(static_text);
				static_text = ft_strdup(temp);
				printf("STATIC TEXT PRE 2 -> %s\n", static_text);
				return (res);
			}
			i++;
		}
	}
	chars_read = BUFFER_SIZE;
	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE - (BUFFER_SIZE - chars_read));
		printf("CHARS READ -> %d\n", chars_read);
		if (chars_read == 0)
			break ;
		buf[chars_read] = '\0';
		printf("BUF -> %s\n", buf);
		i = 0;
		static_text = ft_strjoin(static_text, buf);
		printf("STATIC TEXT - > %s\n", static_text);
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				res = before_new_line(static_text);
				printf("res -> %s\n", res);
				temp = ft_strchr(static_text, '\n');
				printf("temp -> %s\n", temp);
				free(static_text);
				static_text = ft_strdup(temp);
				printf("STATIC TEXT -> %s\n", static_text);
				return (res);
			}
			i++;
		}
	}
	return (static_text);
}

int	main(void)
{
	int				fd;
	char			*buf_res;

	fd = open("file.txt", O_RDONLY);

	printf("\n\nITERACIÓN 1\n");
	buf_res = get_next_line(fd);
	printf("RESULTADO -> %s\n", buf_res);

	printf("\n\nITERACIÓN 2\n");
	buf_res = get_next_line(fd);
	printf("RESULTADO -> %s\n", buf_res);

	printf("\n\nITERACIÓN 3\n");
	buf_res = get_next_line(fd);
	printf("RESULTADO -> %s\n", buf_res);

	printf("\n\nITERACIÓN 4\n");
	buf_res = get_next_line(fd);
	printf("RESULTADO -> %s\n", buf_res);

	printf("\n\nITERACIÓN 5\n");
	buf_res = get_next_line(fd);
	printf("RESULTADO -> %s\n", buf_res);

//	buf_res = get_next_line(fd);
//	buf_res = get_next_line(fd);
//	buf_res = get_next_line(fd);
}

/*
char	*get_next_line(int fd)
{
	char		*buf;
	int			buf_size;
	static int	dif;

	buf_size = find_new_line(fd);
	dif = buf_size - dif;
	if (buf_size == 0)
	{
		printf("No more lines\n");
		return (0);
	}
	printf("new line -> %d\n", buf_size);
	printf("difference -> %d\n", dif);
	return (0);
}
*/

//	buf = (char *)malloc(sizeof(char) * (buf_size +1 - dif));
//	if (!buf)
//		return (0);
//	read(fd, buf, buf_size + 1);
//	buf[buf_size] = '\0';
//	lseek(fd, buf_size + 1, SEEK_SET);
//	return (buf);
	/*
	while ((buf_size = find_new_line(fd)) != 0)
	{
		lseek(fd, buf_size + 1, SEEK_SET);
		printf("%d", buf_size);
	}
	return (0);
	*/
	/*
	buf_size = 15;
	buf = (char *)malloc(sizeof(char) * (buf_size + 1));
	if (!buf)
		return (0);
	read(fd, buf, buf_size);
	printf("%s", buf);
	return (NULL);
	*/



/*
int	main(void)
{
	int		fd;
	char	buf[256];
	int		chars_read;
	int		i;

	fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd, "hey esto es una prueba de un text mas o menos largo043", 56);
	lseek(fd, 0, SEEK_SET);
	while ((chars_read = read(fd, buf, 12)))
	{
		i = 0;
		while (buf != '\n')
		{
			printf(buf[i])
			i++;
		}
		printf("%d\n", chars_read);
		buf[chars_read] = '\0';
		printf("buf -> %s\n", buf);
	}
	return (0);
	}
*/
