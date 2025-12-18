/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_suite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:49:22 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 12:12:09 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*fx to put the lowest node on the top of both stack
and push it on the specifique target node*/

void	ft_push_swap(t_stack **a, t_stack **b)
{
	int		stack_a_len;
	t_stack	*min_node;

	if (ft_stack_sort(*a) == true)
		return ;
	stack_a_len = ft_lst_len(*a);
	if (*a == NULL || stack_a_len == 0)
		return ;
	while (stack_a_len-- > 3)
		ft_push_a_to_b(a, b, 1);
	ft_sort_three(a);
	while (*b)
	{
		ft_init_stack(*a, *b);
		ft_push_lowest_node(a, b);
	}
	ft_complet_node(*a);
	min_node = ft_min_value_node(*a);
	while (*a != min_node)
	{
		if (min_node->lower_med == true)
			ft_rotate_a(a, 1);
		else if (min_node->lower_med == false)
			ft_rev_rotate_a(a, 1);
	}
}
