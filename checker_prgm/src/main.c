/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:30:46 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 15:50:19 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line_cmd;
	int		a_len;

	(1 && (a = NULL), (b = NULL), (line_cmd = NULL));
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_create_stack(&a, argv + 1, 1);
	}
	else
		ft_create_stack(&a, argv + 1, 0);
	a_len = ft_lst_len(a);
	ft_line_cmd(line_cmd, &a, &b);
	if (ft_stack_sort(a) && ft_lst_len(a) == a_len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_print_err(&a, &b, 0);
	if (argc == 2)
		ft_free_split(argv);
	return (0);
}
