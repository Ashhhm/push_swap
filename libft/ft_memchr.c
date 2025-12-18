/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:30:48 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/07 15:50:40 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str_s;
	unsigned char	str_c;
	size_t			i;

	str_s = (unsigned char *) s;
	str_c = (unsigned char) c;
	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str_s[i] == (unsigned char)str_c)
			return ((void *)&str_s[i]);
		i++;
	}
	return (NULL);
}
