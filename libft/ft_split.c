/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:26:52 by hammeah           #+#    #+#             */
/*   Updated: 2025/11/09 19:15:22 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_var(size_t	*end, size_t *i, int *st)
{
	*i = 0;
	*end = 0;
	*st = -1;
}

static int	count_word(const char *s, char c)
{
	int	nb_word;
	int	i;

	i = ((nb_word = 0));
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			nb_word++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (nb_word);
}

char	*ft_strcpy(const char *s, size_t start, size_t end)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret || s[0] == '\0')
		return (NULL);
	i = 0;
	while (start < end)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

static void	*ft_free(char **split, int nb_word)
{
	int	i;

	i = 0;
	while (i < nb_word)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		st;
	size_t	end;
	size_t	i;

	split = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	init_var(&end, &i, &st);
	while (end <= ft_strlen(s))
	{
		if (s[end] != c && st == -1)
			st = end;
		else if ((s[end] == c && st >= 0) || (end == ft_strlen(s) && st >= 0))
		{
			split[i] = ft_strcpy(s, st, end);
			if (!(split[i]))
				return (ft_free(split, i));
			st = -1;
			i++;
		}
		end++;
	}
	split[i] = NULL;
	return (split);
}

/*int	main(void)
{
	char **tabstr;
	int		i;

	tabstr = ft_split("lorempsumdolorsitamet", ' ');
	if (!tabstr)
		printf("NULL");
	else
	{
		i = 0;
		while (tabstr[i])
		{
			printf("%s\n", tabstr[i]);
			printf("i==%d", i);
			i++;
		}
	}
	ft_free(tabstr, i);
	return (0);
}*/
