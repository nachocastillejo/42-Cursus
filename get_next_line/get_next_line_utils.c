/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:07 by igncasti          #+#    #+#             */
/*   Updated: 2024/04/11 13:52:51 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
