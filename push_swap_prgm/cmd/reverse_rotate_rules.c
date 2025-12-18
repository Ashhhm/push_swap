/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:22:18 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 08:04:29 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack **src)
{
	t_stack	*last_node;
	t_stack	*first_node;

	if ((*src) == NULL || (*src)->next == NULL)
		return ;
	first_node = *src;
	last_node = ft_lstlst(*src);
	first_node->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	*src = last_node;
}

void	ft_rev_rotate_a(t_stack **a, int flag)
{
	ft_rev_rotate(a);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	ft_rev_rotate_b(t_stack **b, int flag)
{
	ft_rev_rotate(b);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	ft_rev_rotate_ab(t_stack **a, t_stack **b, int flag)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
