/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 06:59:35 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/15 12:11:23 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	static t_gnllist	*list = NULL;
	char				*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &ret, 0) < 0)
	{
		ft_free_list(list);
		list = NULL;
		return (NULL);
	}
	ret = NULL;
	ft_create_str(fd, &list);
	if (!list)
		return (NULL);
	ft_return_line(list, &ret);
	ft_next_ret(&list);
	if (ret[0] == '\0')
	{
		ft_free_list(list);
		list = NULL;
		free(ret);
		return (NULL);
	}
	return (ret);
}

void	ft_create_str(int fd, t_gnllist **list)
{
	char	*buffer;
	int		byte_read;

	byte_read = 1;
	while (!ft_checking_backslast(*list) && byte_read != 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[byte_read] = '\0';
		ft_add_to_list(buffer, list, byte_read);
		free(buffer);
	}
}

void	ft_add_to_list(char *buffer, t_gnllist **list, int byte_read)
{
	int			i;
	t_gnllist	*lt_node;
	t_gnllist	*n_node;

	n_node = malloc(sizeof(t_gnllist));
	if (!n_node)
		return ;
	n_node->next = NULL;
	n_node->str = malloc(sizeof(char) * (byte_read + 1));
	if (!n_node->str)
		return ;
	i = 0;
	while (buffer[i] && i < byte_read)
	{
		n_node->str[i] = buffer[i];
		i++;
	}
	n_node->str[i] = '\0';
	lt_node = ft_lstlast_b(*list);
	if (lt_node == NULL)
	{
		*list = n_node;
		return ;
	}
	lt_node->next = n_node;
}

void	ft_return_line(t_gnllist *list, char **ret)
{
	int	i;
	int	j;

	if (!list)
		return ;
	*ret = malloc(sizeof(char) * (ft_len_line(list) + 1));
	if (*ret == NULL || !list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				(*ret)[j++] = '\n';
				(*ret)[j] = '\0';
				return ;
			}
			(*ret)[j++] = list->str[i++];
		}
		list = list->next;
	}
	(*ret)[j] = '\0';
}

void	ft_next_ret(t_gnllist **list)
{
	t_gnllist	*lt_node;
	t_gnllist	*n_node;
	int			i;
	int			j;

	lt_node = ft_lstlast_b(*list);
	n_node = malloc(sizeof(t_gnllist));
	if (!list || !n_node)
		return ;
	i = ((j = 0));
	while (lt_node->str[i] && lt_node->str[i] != '\n')
		i++;
	if (lt_node->str && lt_node->str[i] == '\n')
		i++;
	n_node->str = malloc(sizeof(char) * ((ft_strlen_b(lt_node->str) - i) + 1));
	if (!n_node->str)
		return ;
	while (lt_node->str[i])
		n_node->str[j++] = lt_node->str[i++];
	n_node->str[j] = '\0';
	n_node->next = NULL;
	ft_free_list(*list);
	*list = n_node;
}
