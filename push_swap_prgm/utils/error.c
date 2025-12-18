/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:54:27 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/04 19:58:26 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(t_stack **src, char **split, int flag_split)
{
	ft_free_stack(src);
	if (flag_split == 1)
		ft_free_split(split);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_stack(t_stack **src)
{
	t_stack	*tmp;
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*src = NULL;
}

t_stack	*ft_lstlst(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
