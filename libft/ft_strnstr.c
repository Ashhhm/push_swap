/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:21:11 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/05 15:37:58 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	find_len;

	find_len = ft_strlen(to_find);
	if (find_len == 0)
		return ((char *)src);
	i = 0;
	while (src[i] && i < len)
	{
		j = 0;
		while (src[i + j] == to_find[j] && src[i + j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)src + i);
		}
		i++;
	}
	return (NULL);
}
