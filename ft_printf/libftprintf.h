/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:00:00 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/31 20:22:23 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(char const *input, ...);
void			ft_putchar(char c);
void			ft_putnbr(int n, int respect_sign);
void			ft_putstr(char *s);
void			ft_putnbr_base(int nbr, char *base);

#endif