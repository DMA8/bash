/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:05 by arashido          #+#    #+#             */
/*   Updated: 2023/11/28 10:07:11 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_end_index(char *s, char *delimiters, int start)
		// we need to know the index to stop at
{
	t_quotes quotes;

	quotes.is_single = false;
	quotes.is_double = false;
	if (s[start] && find_char(delimiters, s[start]))
	{
		if (s[start + 1] && s[start] == s[start + 1] && !find_char("|",
				s[start]))
			return (start += 2);
				// we cant to check if there is a redirection metacharacter after
		else
			return (start + 1);
	}
	else
	{
		while (s[start])
		{
			set_quote_flag(&quotes, s[start]);
				// checking every character if we have entered a quote
			if (find_char(delimiters, s[start]) && !quotes.is_single
				&& !quotes.is_double)
				break ;
			start++;
		}
	}
	return (start);
}

static int	total_tokens(char *s, char *delimiters)
		// important for allocating the number of words we will have
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!find_char(delimiters, s[i]))
			i = get_end_index(s, delimiters, i);
		else
		{
			if (s[i + 1] && (s[i] == s[i + 1]) && !find_char("|", s[i]))
				i += 2;
			else
				i++;
		}
		count++;
	}
	return (count);
}

static char	**split_on_delim(char *s, char **array, char *delimiters)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (i < (total_tokens(s, delimiters)))
	{
		if (s[start] && find_char(delimiters, s[start]))
		{
			if (s[start + 1] && s[start] == s[start + 1] && !find_char("|",
					s[start]))
				array[i++] = ft_substr(s, start, 2);
			else
				array[i++] = ft_substr(s, start, 1);
		}
		else
			array[i++] = ft_substr(s, start, get_end_index(s, delimiters, start)
				- start);
		start = get_end_index(s, delimiters, start);
	}
	array[i] = NULL;
	return (array);
}

char	**ft_strtok(char *s)
{
	char	**array;
	char	*delimiters;

	delimiters = "<|>";
	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (total_tokens(s, delimiters) + 1));
	if (array == NULL)
		return (NULL);
	array = split_on_delim(s, array, delimiters);
	return (array);
}
