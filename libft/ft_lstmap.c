/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:21:42 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/09 20:03:40 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*node;
	void	*box;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		box = f(lst->content);
		if (!box)
			return (ft_lstclear(&n_lst, del), NULL);
		node = ft_lstnew(box);
		if (!node)
		{
			del(box);
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, node);
		lst = lst->next;
	}
	return (n_lst);
}
