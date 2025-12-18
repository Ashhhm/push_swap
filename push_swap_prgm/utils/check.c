/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:25:25 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/11 19:23:16 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

long	ft_atol(char *str)
{
	long long	nb;
	int			sign;
	int			i;

	nb = ((i = 0));
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * sign < INT_MIN || nb * sign > INT_MAX)
			return (LONG_MAX);
		i++;
	}
	return (sign * nb);
}

int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_double(t_stack *a, int nb)
{
	t_stack	*current_node;

	if (a == NULL)
		return (1);
	current_node = a;
	while (current_node)
	{
		if (current_node->value == nb)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

void	ft_create_node(t_stack **a, int nb)
{
	t_stack	*current_node;
	t_stack	*last_node;

	current_node = malloc(sizeof(t_stack));
	if (!current_node)
		return ;
	*current_node = (t_stack){0};
	current_node->value = nb;
	current_node->next = NULL;
	if (*a == NULL)
	{
		current_node->prev = NULL;
		*a = current_node;
	}
	else
	{
		last_node = ft_lstlst(*a);
		last_node->next = current_node;
		current_node->prev = last_node;
	}
}

void	ft_create_stack(t_stack **a, char **str, int flag_split)
{
	int			i;
	long long	nb;

	i = 0;
	while (str[i])
	{
		if (!ft_str_is_digit(str[i]))
			return (ft_print_error(a, str, flag_split));
		nb = ft_atol(str[i]);
		if (nb == LONG_MAX)
			return (ft_print_error(a, str, flag_split));
		if (!ft_check_double(*a, (int)nb))
			return (ft_print_error(a, str, flag_split));
		ft_create_node(a, (int)nb);
		i++;
	}
}
