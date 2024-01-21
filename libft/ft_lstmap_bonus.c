/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:08:09 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/21 23:23:30 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Descripción: Itera la lista ’lst’ y aplica la función
	 ’f’ al contenido de cada nodo. Crea una lista resultante
	de la aplicación correcta y sucesiva de la función
	’f’ sobre cada nodo. La función ’del’ se utiliza
	para eliminar el contenido de un nodo, si hace falta.

	Resultado:
		1. Creamos res, donde se irá guardando 
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;

	res = NULL;
	while (lst)
	{
		node = ft_lstnew(0);
		if (!node)
		{
			ft_lstclear(&res, (*del));
			return (NULL);
		}
		node->content = f(lst->content);
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
