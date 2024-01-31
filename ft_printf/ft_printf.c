/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:09:36 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/31 20:20:43 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg(char const *input, va_list args)
{
	if (*(input + 1) == 'c')
		ft_putchar(va_arg(args, int));
	if (*(input + 1) == 's')
		ft_putstr(va_arg(args, char *));
	if (*(input + 1) == 'p' || *(input + 1) == 'x')
		ft_putnbr_base((int)va_arg(args, void *), "0123456789abcdef");
	if (*(input + 1) == 'd' || *(input + 1) == 'i')
		ft_putnbr(va_arg(args, int), 1);
	if (*(input + 1) == 'u')
		ft_putnbr(va_arg(args, int), 0);
	if (*(input + 1) == 'X')
		ft_putnbr_base((int)va_arg(args, void *), "0123456789ABCDEF");
	if (*(input + 1) == '%')
		ft_putchar('%');
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
			print_arg(input, args);
			input += 2;
			res += 2;
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
	ft_printf("Mi porcentaje es %d%%", 42);
	//ft_printf("Tengo %s. Mi inicial %c. Tengo %i", 20, "treinta", 'N', 1);
	//ft_printf("Mi edad es %u", -42);
	return (0);
}*/
