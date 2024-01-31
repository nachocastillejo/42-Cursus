/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:19:02 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/31 22:00:44 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	wrong_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] < 32 || str[i] > 126)
			return (1);
		while (j < i)
		{
			if (str[j] == str[i])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base, int *res)
{
	if (wrong_base(base))
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / str_len(base), base, res);
		ft_putnbr_base(nbr % str_len(base), base, res);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', res);
		*res += 1;
		nbr = -nbr;
	}
	if (nbr >= str_len(base))
	{
		ft_putnbr_base(nbr / str_len(base), base, res);
		ft_putnbr_base(nbr % str_len(base), base, res);
	}
	else
	{
		ft_putchar(base[nbr % str_len(base)], res);
		*res += 1;
	}
}
/*
int	main(void)
{
	int	i;
	char	*base;

	i = 42;
	base = "\n0123456789abcdef";
	ft_putnbr_base(i, base);
}*/