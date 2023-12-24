/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:05 by arashido          #+#    #+#             */
/*   Updated: 2023/11/30 18:50:02 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_end_index_sp(char *s, char *delimiters, int start)
{
	t_quotes	quotes;
	int			end;

	quotes.is_single = false;
	quotes.is_double = false;
	end = start;
	while (s[end])
	{
		set_quote_flag(&quotes, s[end]);
		if (find_char(delimiters, s[end]) && !quotes.is_single
			&& !quotes.is_double)
			break ;
		end++;
	}
	return (end);
}

static int	num_words(char *s, char *delimiters)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		// check for occurence of delimiter
		if (!find_char(delimiters, s[i]))
		{
			i = get_end_index_sp(s, delimiters, i);
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	**remove_spaces(char *s, char **array, char *delimiters)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (i < (num_words(s, delimiters)))
	{
		while (s[start] && (find_char(delimiters, s[start])))
			start++;
		array[i++] = ft_substr(s, start, (get_end_index_sp(s, delimiters, start)
				- start));
		start = get_end_index_sp(s, delimiters, start);
	}
	array[i] = NULL;
	return (array);
}

char	**ft_space(char *s)
{
	char	**array;
	char	*delimiters;

	// spaces we split on
	delimiters = "\t  \n\v\f\b";
	if (!s)
		return (NULL);
	int i = 0;
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] == '\0')
			return (NULL);
		i++;
	}

	array = (char **)malloc(sizeof(char *) * (num_words(s, delimiters) + 1));
	// allocate the number of words
	if (array == NULL)
		return (NULL);
	array = remove_spaces(s, array, delimiters);
	return (array);
}
