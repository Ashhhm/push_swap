/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:25:55 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/05 15:30:04 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*ret;

	ret = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	s_len = 0;
	while (s1[s_len])
	{
		ret[s_len] = s1[s_len];
		s_len++;
	}
	ret[s_len] = '\0';
	return (ret);
}
