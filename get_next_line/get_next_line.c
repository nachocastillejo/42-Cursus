/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:06:18 by igncasti          #+#    #+#             */
/*   Updated: 2024/04/11 13:42:11 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			buf_static_value;

	buf_static_value = find_new_line(fd);
	buf = (char *)malloc(sizeof(char) * (buf_static_value + 1));
	if (!buf)
		return (0);
	read(fd, buf, buf_static_value + 1);
	buf[buf_static_value] = '\0';
//	lseek(fd, buf_static_value + 1, SEEK_SET);
	return (buf);
	/*
	while ((buf_static_value = find_new_line(fd)) != 0)
	{
		lseek(fd, buf_static_value + 1, SEEK_SET);
		printf("%d", buf_static_value);
	}
	return (0);
	*/
	/*
	buf_static_value = 15;
	buf = (char *)malloc(sizeof(char) * (buf_static_value + 1));
	if (!buf)
		return (0);
	read(fd, buf, buf_static_value);
	printf("%s", buf);
	return (NULL);
	*/
}

int	main(void)
{
	int		fd;
	char	*buf_res;

	fd = open("file.txt", O_RDONLY);
	buf_res = get_next_line(fd);
	printf("%s\n", buf_res);
	buf_res = get_next_line(fd);
	printf("%s\n", buf_res);
	close(fd);
	/*while ((buf_res = get_next_line(fd)) != 0)
	{
		printf("%s\n", buf_res);
	}*/
}

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
