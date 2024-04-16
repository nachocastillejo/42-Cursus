/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:06:18 by igncasti          #+#    #+#             */
/*   Updated: 2024/04/16 21:28:35 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (static_text)
	{
		//printf("STATIC TEXT PRE 1 -> %s\n", static_text);
		i = 0;
		while (static_text[i])
		{
			if (static_text[i] == '\n')
			{
				res = before_new_line(static_text);
				//printf("res PRE -> %s\n", res);
				temp = ft_strdup(ft_strchr(static_text, '\n'));
				//printf("temp PRE -> %s\n", temp);
				free_storage(&static_text);
				static_text = temp;
				//printf("STATIC TEXT PRE 2 -> %s\n", static_text);
				return (res);
			}
			i++;
		}
	}
	chars_read = BUFFER_SIZE;
	j = 0;
	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE - (BUFFER_SIZE - chars_read));
		//printf("CHARS READ -> %d\n", chars_read);
		//printf("J -> %d\n", j);
		//if (chars_read == 0 && j > 0)
		//	return (static_text);
		if (chars_read == 0)
		{
			if (static_text)
			{
				//printf("CONDITION\n");
				//res = ft_strdup(static_text);
				res = ft_strdup(static_text);
				printf("RES -> %s\n", static_text);
				free_storage(&static_text);
				static_text = 0;
				return (res);
			}
			else
				return (0);
		}
		buf[chars_read] = '\0';
		//printf("BUF -> %s\n", buf);
		temp = static_text;
		static_text = ft_strjoin(static_text, buf);
		if (temp)
			free(temp);
		//printf("STATIC TEXT -> %s\n", static_text);
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				res = before_new_line(static_text);
				//printf("res -> %s\n", res);
				temp = ft_strdup(ft_strchr(static_text, '\n'));
				//printf("temp -> %s\n", temp);
				if (static_text)
					free_storage(&static_text);
				static_text = temp;
				//printf("STATIC TEXT -> %s\n", static_text);
				return (res);
			}
			i++;
		}
		j++;
	}
	return (0);
}
/*
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
*/