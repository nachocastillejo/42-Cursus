/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:22:39 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/31 22:14:21 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int respect_sign, int *res)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		if (respect_sign)
			ft_putchar('-', res);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, 1, res);
		ft_putnbr(n % 10, 1, res);
	}
	if (n <= 9)
		ft_putchar(n + '0', res);
}
