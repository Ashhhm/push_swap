/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:19:59 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/18 23:17:33 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;
	int		split_flag;

	(1 && (a = NULL), (b = NULL), (split_flag = 0));
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		split_flag = 1;
		ft_create_stack(&a, split, split_flag);
	}
	else
		ft_create_stack(&a, argv + 1, split_flag);
	ft_push_swap(&a, &b);
	if (ft_stack_sort(a) == true)
	{
		ft_free_stack(&a);
		ft_free_stack(&b);
		if (split_flag == 1)
			ft_free_split(split);
	}
	return (0);
}
