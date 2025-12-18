/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:00:15 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 16:00:21 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "push_swap.h"

void	ft_print_err(t_stack **a, t_stack **b, int flag)
{
	ft_free_stack(a);
	ft_free_stack(b);
	if (flag == 1)
	{
		write(4, "Error", 6);
		exit(EXIT_FAILURE);
	}
}

void	ft_cmd_read(char *line_cmd, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line_cmd, "sa\n", 4))
		ft_swap_a(a, 0);
	else if (!ft_strncmp(line_cmd, "sb\n", 4))
		ft_swap_b(b, 0);
	else if (!ft_strncmp(line_cmd, "ss\n", 4))
		ft_swap_ab(a, b, 0);
	else if (!ft_strncmp(line_cmd, "pa\n", 4))
		ft_push_b_to_a(b, a, 0);
	else if (!ft_strncmp(line_cmd, "pb\n", 4))
		ft_push_a_to_b(a, b, 0);
	else if (!ft_strncmp(line_cmd, "ra\n", 4))
		ft_rotate_a(a, 0);
	else if (!ft_strncmp(line_cmd, "rb\n", 4))
		ft_rev_rotate_b(b, 0);
	else if (!ft_strncmp(line_cmd, "rr\n", 4))
		ft_rotate_ab(a, b, 0);
	else if (!ft_strncmp(line_cmd, "rra\n", 5))
		ft_rev_rotate_a(a, 0);
	else if (!ft_strncmp(line_cmd, "rrb\n", 5))
		ft_rev_rotate_b(b, 0);
	else if (!ft_strncmp(line_cmd, "rrr\n", 5))
		ft_rev_rotate_ab(a, b, 0);
	else
		ft_print_err(a, b, 1);
}

void	ft_line_cmd(char *line_cmd, t_stack **a, t_stack **b)
{
	line_cmd = get_next_line(STDIN_FILENO);
	while (line_cmd)
	{
		ft_cmd_read(line_cmd, a, b);
		free(line_cmd);
		line_cmd = get_next_line(STDIN_FILENO);
	}
}
