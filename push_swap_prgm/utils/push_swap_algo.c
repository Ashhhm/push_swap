/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:10:48 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 08:09:16 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_lowest_push(t_stack *b)
{
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (b->flag_lower_to_push == true)
			return (b);
		b = b->next;
	}
	return (NULL);
}

void	ft_lowest_on_top_a(t_stack **src, t_stack *lowest)
{
	t_stack	*current;

	if (*src == NULL || lowest == NULL)
		return ;
	current = lowest->target_node;
	while (*src != current)
	{
		if (current->lower_med == true)
			ft_rotate_a(src, 1);
		else if (current->lower_med == false)
			ft_rev_rotate_a(src, 1);
	}
}

void	ft_lowest_on_top_b(t_stack **src, t_stack *lowest)
{
	if (*src == NULL || lowest == NULL)
		return ;
	while (*src != lowest)
	{
		if (lowest->lower_med == true)
			ft_rotate_b(src, 1);
		else if (lowest->lower_med == false)
			ft_rev_rotate_b(src, 1);
	}
}

void	ft_push_lowest_node(t_stack **a, t_stack **b)
{
	t_stack	*lowest_node;

	lowest_node = ft_find_lowest_push(*b);
	if (lowest_node == NULL)
		return ;
	if (lowest_node->lower_med == true
		&& lowest_node->target_node->lower_med == true)
		ft_rotate_stacks(a, b, lowest_node);
	else if (lowest_node->lower_med == false
		&& lowest_node->target_node->lower_med == false)
		ft_rev_rotate_stacks(a, b, lowest_node);
	ft_lowest_on_top_a(a, lowest_node);
	ft_lowest_on_top_b(b, lowest_node);
	ft_push_b_to_a(b, a, 1);
}

void	ft_rotate_stacks(t_stack **a, t_stack **b, t_stack *lowest)
{
	t_stack	*target;

	if (!lowest)
		return ;
	target = lowest->target_node;
	while (*a != target && *b != lowest)
		ft_rotate_ab(a, b, 1);
	ft_complet_node(*a);
	ft_complet_node(*b);
	ft_lowest_on_top_a(a, lowest);
	ft_lowest_on_top_b(b, lowest);
}
