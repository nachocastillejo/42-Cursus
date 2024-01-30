/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:09:36 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/30 23:37:38 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg(char const *input, va_list args)
{
	if (*(input + 1) == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (*(input + 1) == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (*(input + 1) == 'd' || *(input + 1) == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);

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

int	main(void)
{
	//printf("Mi edad es %d y la tuya?. Yo tengo %d", 20, 28);
	ft_printf("Mi edad es %d y la tuya?. Yo tengo %s. Mi inicial es %c", 20, "treinta", 'N');
	return (0);
}
