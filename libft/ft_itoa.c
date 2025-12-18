/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:53:12 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/07 14:42:54 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_n(long n)
{
	int	n_len;

	n_len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n_len++;
	while (n != 0)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	len_str;
	long	num;

	len_str = len_n(n);
	ret = malloc(sizeof(char) * (len_str + 1));
	if (!ret)
		return (NULL);
	num = n;
	if (num < 0)
		num = -num;
	ret[len_str] = '\0';
	if (num == 0)
		ret[0] = '0';
	else
	{
		while (num != 0 && len_str--)
		{
			ret[len_str] = (num % 10) + '0';
			num /= 10;
		}
		if (n < 0)
			ret[0] = '-';
	}
	return (ret);
}

/*int main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-789));
	return (0);
}*/
