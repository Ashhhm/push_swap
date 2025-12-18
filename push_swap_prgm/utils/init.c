/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:43:38 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/12 13:20:08 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_complet_node(t_stack *src)
{
	int	stack_len;
	int	nb_index;

	if (src == NULL)
		return ;
	stack_len = ft_lst_len(src);
	nb_index = 0;
	while (src)
	{
		src->index = nb_index;
		if (src->index <= stack_len / 2)
			src->lower_med = true;
		else if (src->index > stack_len / 2)
			src->lower_med = false;
		src = src->next;
		nb_index++;
	}
}

void	ft_find_target(t_stack *set, t_stack *src)
{
	t_stack	*target;
	t_stack	*node_set;
	long	flag;

	while (src)
	{
		flag = INT_MAX;
		node_set = set;
		while (node_set)
		{
			if (node_set->value > src->value && node_set->value < flag)
			{
				flag = node_set->value;
				target = node_set;
			}
			node_set = node_set->next;
		}
		if (flag == INT_MAX)
			target = ft_min_value_node(set);
		src->target_node = target;
		src = src->next;
	}
}

void	ft_push_cost(t_stack *set, t_stack *src)
{
	t_stack	*target;
	int		cost_src;
	int		lst_len_set;
	int		lst_len_src;

	lst_len_set = ft_lst_len(set);
	lst_len_src = ft_lst_len(src);
	while (src)
	{
		cost_src = 0;
		target = src->target_node;
		if (src->lower_med == true)
			cost_src += src->index;
		if (src->lower_med == false)
			cost_src += lst_len_src - src->index;
		if (target->lower_med == true)
			cost_src += target->index;
		if (target->lower_med == false)
			cost_src += lst_len_set - target->index;
		src->push_cost = cost_src;
		src = src->next;
	}
}

void	ft_find_lowest(t_stack *src)
{
	long	cost_flag;
	t_stack	*lowest_node;

	if (src == NULL)
		return ;
	cost_flag = INT_MAX;
	while (src)
	{
		if (src->push_cost < cost_flag)
		{
			cost_flag = src->push_cost;
			lowest_node = src;
		}
		src = src->next;
	}
	if (cost_flag != INT_MAX)
		lowest_node->flag_lower_to_push = true;
}

void	ft_init_stack(t_stack *a, t_stack *b)
{
	ft_complet_node(a);
	ft_complet_node(b);
	ft_find_target(a, b);
	ft_push_cost(a, b);
	ft_find_lowest(b);
}
