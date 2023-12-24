/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:24:11 by arashido          #+#    #+#             */
/*   Updated: 2023/11/22 07:27:28 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// make duplicate
char	**dup_array(char **src)
{
	int		num_words;
	char	**dest;
	int		i;

	num_words = ft_array_len(src);
	dest = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < num_words)
		dest[i] = ft_strdup(src[i]);
	dest[i] = NULL;
	return (dest);
}

// length of array
int	ft_array_len(char **str)
{
	int	str_rows;

	str_rows = 0;
	if (!str)
		return (0);
	while (str[str_rows] != NULL)
		str_rows++;
	return (str_rows);
}

// check if letter inside array
bool	find_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (true);
		i++;
	}
	if ((char)c == '\0')
		return (true);
	return (false);
}
