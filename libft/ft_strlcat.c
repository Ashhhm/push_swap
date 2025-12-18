/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:51:36 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/06 12:27:40 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	ret_dst_len;
	size_t	i;

	dstlen = ft_strlen(dst);
	ret_dst_len = dstlen;
	srclen = ft_strlen(src);
	if (dstsize < 1)
		return (srclen + dstsize);
	i = 0;
	while (src[i] && dstlen < dstsize - 1)
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	if (dstsize < ret_dst_len)
		return (srclen + dstsize);
	else
		return (srclen + ret_dst_len);
}
