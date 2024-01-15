/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:57:10 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/13 12:57:10 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
char	**ft_split(char const *s, char c);
{
	char	**res;

	res[0]
}*/

int	main(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char*) * 2);
	if (!res)
		return (0);
	res[0] = "hola";
	res[1] = "adios";
	/*printf("%s", ft_split("hola me llamo Nacho", ' ')[0]);
	*/
	printf("%s", res[0]);
}
