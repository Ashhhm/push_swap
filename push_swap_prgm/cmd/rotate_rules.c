/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:32:18 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 08:05:14 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **src)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if ((*src)->next == NULL || *src == NULL)
		return ;
	first_node = *src;
	last_node = ft_lstlst(*src);
	(*src) = (*src)->next;
	(*src)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
}

void	ft_rotate_a(t_stack **a, int flag)
{
	ft_rotate(a);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **b, int flag)
{
	ft_rotate(b);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_stack **a, t_stack **b, int flag)
{
	ft_rotate(a);
	ft_rotate(b);
	if (flag == 1)
		write(1, "rr\n", 3);
}
