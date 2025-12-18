/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:28:43 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/07 19:28:44 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nb_node;
	t_list	*ptr;

	ptr = lst;
	nb_node = 0;
	while (ptr != NULL)
	{
		nb_node++;
		ptr = ptr->next;
	}
	return (nb_node);
}
