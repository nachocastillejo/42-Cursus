/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:51:42 by igncasti          #+#    #+#             */
/*   Updated: 2024/02/11 19:04:53 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	while_str(char *s, int i, int *res)
{
	while (s[i] && *res >= 0)
	{
		if (write(1, &s[i], 1) < 0)
			*res -= 1;
		else
			*res += 1;
		i++;
	}
}

void	ft_putstr(char *s, int *res)
{
	int		i;

	i = 0;
	if (s != NULL)
		while_str(s, i, res);
	else
		while_str("(null)", i, res);
}
