/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 06:58:39 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 12:11:18 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_checking_backslast(t_gnllist *list)
{
	int			i;
	t_gnllist	*node;

	if (list == NULL)
		return (0);
	node = ft_lstlast_b(list);
	i = 0;
	while (node->str[i] && i < BUFFER_SIZE)
	{
		if (node->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_gnllist	*ft_lstlast_b(t_gnllist *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

int	ft_len_line(t_gnllist *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_free_list(t_gnllist *list)
{
	t_gnllist	*node;
	t_gnllist	*next_node;

	node = list;
	while (node)
	{
		free(node->str);
		next_node = node->next;
		free(node);
		node = next_node;
	}
}

int	ft_strlen_b(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
