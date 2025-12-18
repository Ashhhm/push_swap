/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:43:22 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 11:59:39 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*node_src;

	if (*src == NULL)
		return ;
	node_src = *src;
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_src->prev = NULL;
	if (*dst == NULL)
	{
		*dst = node_src;
		node_src->next = NULL;
	}
	else
	{
		node_src->next = *dst;
		(*dst)->prev = node_src;
		*dst = node_src;
	}
}

void	ft_push_b_to_a(t_stack **b, t_stack **a, int flag)
{
	ft_push(b, a);
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	ft_push_a_to_b(t_stack **a, t_stack **b, int flag)
{
	ft_push(a, b);
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	ft_rev_rotate_stacks(t_stack **a, t_stack **b, t_stack *lowest)
{
	t_stack	*target;

	if (!lowest)
		return ;
	target = lowest->target_node;
	while (*a != target && *b != lowest)
		ft_rev_rotate_ab(a, b, 1);
	ft_complet_node(*a);
	ft_complet_node(*b);
	ft_lowest_on_top_a(a, lowest);
	ft_lowest_on_top_b(b, lowest);
}
