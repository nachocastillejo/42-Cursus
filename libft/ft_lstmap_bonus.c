/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncasti <igncasti@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:08:09 by igncasti          #+#    #+#             */
/*   Updated: 2024/01/28 12:18:49 by igncasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
