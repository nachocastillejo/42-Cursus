/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:06:18 by igncasti          #+#    #+#             */
/*   Updated: 2024/04/18 13:45:18 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_leaks(void)
{
	system("leaks -q a.out");
}

void	free_storage(char **string)
{
	free(*string);
	*string = NULL;
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			chars_read;
	char		*temp;
	char		*res;
	static char	*static_text;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (static_text)
			free_storage(&static_text);
		return (NULL);
	}
	if (static_text)// && static_text[0] != '\n')
	{
		//printf("STATIC TEXT PRE 1 -> %s\n", static_text);
		i = 0;
		while (static_text[i])
		{
			if (static_text[i] == '\n')
			{
				res = before_new_line(static_text);
				//return (0);
				//res = before_new_line(static_text);
				//printf("res PRE -> %s\n", res);
				if (res)
				{
					temp = ft_strdup(ft_strchr(static_text, '\n'));
					//printf("temp PRE -> %s\n", temp);
					free_storage(&static_text);
					static_text = temp;
					//printf("STATIC TEXT PRE 2 -> %s\n", static_text);
					return (res);
				}
				else
					return (0);
			}
			i++;
		}
	}
	chars_read = BUFFER_SIZE;
	j = 0;
	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		//printf("CHARS READ -> %d\n", chars_read);
		//printf("LECTURA %d\n", j + 1);
		if (chars_read == 0)
		{
			//printf("STATIC TEXT -> %s\n", static_text);
			if (static_text && static_text[0] && static_text[0] != '\n')
			{
				//printf("CONDITION\n");
				//temp = static_text;
				res = before_new_line(static_text);
				//if (temp)
				//	free(temp);
				//printf("RES -> %s\n", static_text);
				free_storage(&static_text);
				static_text = 0;
				//if (temp)
				//	free(temp);
				return (res);
			}
			else
			{
				if (static_text)
					free_storage(&static_text);
				return (0);
			}
		}
		buf[chars_read] = '\0';
		//printf("BUF -> %s\n", buf);
		// temp = ft_strjoin(static_text, buf);
		// free_storage(&static_text);
		// static_text = temp;
		// temp = ft_strdup(static_text); // comentado ultimamente, desscomentar
		// if (static_text)
		// 	free_storage(&static_text);
		static_text = ft_strjoin(static_text, buf);
		//printf("STATIC TEXT -> %s\n", static_text);
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				res = before_new_line(static_text);
				//res = before_new_line(temp);
				//if (temp)
				//	free(temp);
				//printf("res -> %s\n", res);
				if (res)
				{
					temp = ft_strdup(ft_strchr(static_text, '\n'));
					//printf("temp -> %s\n", temp);
					if (static_text)
						free_storage(&static_text);
					static_text = ft_strdup(temp);
					if (temp)
						free(temp); // SI HACE FALTA
					return (res);
				}
			}
			i++;
		}
		j++;
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