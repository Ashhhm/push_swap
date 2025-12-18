/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:59:36 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/18 22:19:31 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	t_stack	*highest_node;

	if (*a == NULL)
		return ;
	highest_node = ft_max_value_node(*a);
	if (*a == highest_node)
		ft_rotate_a(a, 1);
	else if ((*a)->next == highest_node)
		ft_rev_rotate_a(a, 1);
	if ((*a)->value > (*a)->next->value)
		ft_swap_a(a, 1);
}

t_stack	*ft_max_value_node(t_stack *a)
{
	long	max_value;
	t_stack	*max_node;

	if (a == NULL)
		return (NULL);
	max_value = INT_MIN;
	while (a)
	{
		if (a->value > max_value)
		{
			max_value = a->value;
			max_node = a;
		}
		a = a->next;
	}
	if (max_value == INT_MIN)
		return (NULL);
	return (max_node);
}

bool	ft_stack_sort(t_stack *src)
{
	if (src == NULL)
		return (true);
	while (src->next)
	{
		if (src->value > src->next->value)
			return (false);
		src = src->next;
	}
	return (true);
}

int	ft_lst_len(t_stack *a)
{
	int	len;

	if (a == NULL)
		return (0);
	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_stack	*ft_min_value_node(t_stack *a)
{
	long	min_value;
	t_stack	*min_node;

	if (a == NULL)
		return (NULL);
	min_value = INT_MAX;
	while (a)
	{
		if (a->value < min_value)
		{
			min_value = a->value;
			min_node = a;
		}
		a = a->next;
	}
	if (min_value == INT_MAX)
		return (NULL);
	return (min_node);
}
