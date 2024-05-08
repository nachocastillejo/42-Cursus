/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:06:18 by igncasti          #+#    #+#             */
/*   Updated: 2024/05/08 20:07:17 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_result(char **static_text, char **res, char **temp)
{
	*res = before_new_line(*static_text);
	if (*res)
	{
		*temp = ft_strdup(ft_strchr(*static_text, '\n'));
		if (*static_text)
			free_storage(static_text);
		*static_text = ft_strdup(*temp);
		if (*temp)
			free(*temp);
		return (1);
	}
	return (0);
}

int	check_static(char **static_text, char **res, char **temp)
{
	int	i;

	i = 0;
	while ((*static_text)[i])
	{
		if ((*static_text)[i] == '\n')
		{
			if (get_result(static_text, res, temp))
				return (1);
		}
		i++;
	}
	return (0);
}

char	*chars_read_is_zero(char **static_text, char **res)
{
	if (*static_text && (*static_text)[0] && (*static_text)[0] != '\n')
	{
		*res = before_new_line(*static_text);
		free_storage(static_text);
		*static_text = 0;
		return (*res);
	}
	else
	{
		if (*static_text)
			free_storage(static_text);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			chars_read;
	char		*temp;
	char		*res;
	static char	*static_text;
	int			i;

	temp = NULL;
	if (read(fd, 0, 0) < 0)
	{
		if (static_text)
			free_storage(&static_text);
		return (NULL);
	}
	if (static_text)
	{
		if (check_static(&static_text, &res, &temp))
			return (res);
	}
	chars_read = BUFFER_SIZE;
	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == 0)
			return (chars_read_is_zero(&static_text, &res));
		buf[chars_read] = '\0';
		static_text = ft_strjoin(static_text, buf);
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				if (get_result(&static_text, &res, &temp))
					return (res);
			}
			i++;
		}
	}
	return (0);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 1;
// 	fd = open("file.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%d.: %s", i, line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	close(fd);
// 	atexit(ft_leaks);
// }

// int	main(void)
// {
// 	int				fd;
// 	char			*buf_res;

// 	atexit(ft_leaks);
// 	fd = open("file.txt", O_RDONLY);

// 	printf("\n\nITERACIÓN 1\n");
// 	buf_res = get_next_line(fd);
// 	printf("RESULTADO -> %s\n", buf_res);
// 	free(buf_res);

// 	printf("\n\nITERACIÓN 2\n");
// 	buf_res = get_next_line(fd);
// 	printf("RESULTADO -> %s\n", buf_res);
// 	free(buf_res);

// 	printf("\n\nITERACIÓN 3\n");
// 	buf_res = get_next_line(fd);
// 	printf("RESULTADO -> %s\n", buf_res);
// 	free(buf_res);
// 	printf("\n\nITERACIÓN 4\n");
// 	buf_res = get_next_line(fd);
// 	printf("RESULTADO -> %s\n", buf_res);
// 	free(buf_res);

// 	printf("\n\nITERACIÓN 5\n");
// 	buf_res = get_next_line(fd);
// 	printf("RESULTADO -> %s\n", buf_res);
// 	free(buf_res);

// 	printf("\n\nITERACIÓN 6\n");
// 	buf_res = get_next_line(fd);
// 	printf("RESULTADO -> %s\n", buf_res);

// 	free(buf_res);
// 	// buf_res = get_next_line(fd);
// 	// buf_res = get_next_line(fd);
// 	// buf_res = get_next_line(fd);
// }

/*
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			chars_read;
	char		*temp;
	char		*res;
	static char	*static_text;
	int			i;

	temp = NULL;
	if (read(fd, 0, 0) < 0)
	{
		if (static_text)
			free_storage(&static_text);
		return (NULL);
	}
	if (static_text)
	{
		if (check_static(&static_text, &res, &temp))
			return (res);
	}
	chars_read = BUFFER_SIZE;
	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == 0)
			return (chars_read_is_zero(&static_text, &res));
		buf[chars_read] = '\0';
		static_text = ft_strjoin(static_text, buf);
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				if (get_result(&static_text, &res, &temp))
					return (res);
			}
			i++;
		}
	}
	return (0);
}
*/