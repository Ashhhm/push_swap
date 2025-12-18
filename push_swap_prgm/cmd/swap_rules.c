/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:53:43 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 08:06:09 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **src)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if ((*src) == NULL || (*src)->next == NULL)
		return ;
	first_node = *src;
	second_node = (*src)->next;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	second_node->prev = NULL;
	if (first_node->next)
	{
		first_node->next->prev = first_node;
		*src = second_node;
	}
}

void	ft_swap_a(t_stack **a, int flag)
{
	ft_swap(a);
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **b, int flag)
{
	ft_swap(b);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_swap_ab(t_stack **a, t_stack **b, int flag)
{
	ft_swap(a);
	ft_swap(b);
	if (flag == 1)
		write(1, "ss\n", 3);
}
