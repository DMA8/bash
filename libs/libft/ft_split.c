/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:34:08 by arashido          #+#    #+#             */
/*   Updated: 2023/01/23 17:28:27 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!(s))
		return (0);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!(split))
		return (0);
	start = 0;
	end = 0;
	i = 0;
	while (i < count_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i++] = ft_substr(s, start, (end - start));
		start = end;
	}
	split[i] = 0;
	return (split);
}

// int	main(void)
// {
// 	char	**tab;
// 	int		i;

// 	i = 0;
// 	tab = ft_split("hello world", ' ');
// 	while (tab[i])
// 	{
// 		printf ("tab[%d] = %s\n", i, tab[i]);
// 		i++;
// 	}
// }
