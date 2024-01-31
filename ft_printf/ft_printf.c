/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:09:36 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/31 22:16:02 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(char const *input, va_list args, int *res)
{
	if (*(input + 1) == 'c')
		ft_putchar(va_arg(args, int), res);
	if (*(input + 1) == 's')
		ft_putstr(va_arg(args, char *), res);
	if (*(input + 1) == 'p' || *(input + 1) == 'x')
		ft_putnbr_base((int)va_arg(args, void *), "0123456789abcdef", res);
	if (*(input + 1) == 'd' || *(input + 1) == 'i')
		ft_putnbr(va_arg(args, int), 1, res);
	if (*(input + 1) == 'u')
		ft_putnbr(va_arg(args, int), 0, res);
	if (*(input + 1) == 'X')
		ft_putnbr_base((int)va_arg(args, void *), "0123456789ABCDEF", res);
	if (*(input + 1) == '%')
		ft_putchar('%', res);
}

int	ft_printf(char const *input, ...)
{
	va_list	args;
	int		res;

	res = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			print_arg(input, args, &res);
			input += 2;
		}
		else
		{
			write(1, input, 1);
			res++;
			input ++;
		}
	}
	va_end(args);
	return (res);
}
/*
int	main(void)
{
	int i;

	i = ft_printf("%s%d", "Nacho", 28);
	ft_printf("%d", i);
	//ft_printf("%c", '0');
	//ft_printf("Mi edad es %u", -42222);
	return (0);
}*/
