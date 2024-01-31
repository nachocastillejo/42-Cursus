/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:00:00 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/31 21:53:44 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int				ft_printf(char const *input, ...);
void			ft_putchar(char c, int *res);
void			ft_putnbr(int n, int respect_sign, int *res);
void			ft_putstr(char *s, int *res);
void			ft_putnbr_base(int nbr, char *base, int *res);

#endif