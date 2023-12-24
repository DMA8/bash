/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:13:11 by arashido          #+#    #+#             */
/*   Updated: 2023/11/28 10:06:38 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	needs_expansion(char *str)
{
	t_quotes	quote;
	int			start;

	start = 0;
	quote.is_single = false;
	quote.is_double = false;
	while (str[start] != '\0')
	{
		set_quote_flag(&quote, str[start]);
			// checking every character if we have entered a quote
		if (str[start] == '$' && !quote.is_single
			&& !find_char("\" '/~+=%^{}:\t\v\f\n; '\0'", str[start + 1]))
			return (true);
		start++;
	}
	return (false);
}

int	get_search_var_end(char *str, int start)
{
	if (str[start + 1] && find_char("$?", str[start + 1]))
		return (start + 1);
	start++;
	while (str[start])
	{
		if (find_char("\" '/~+=$%^{}:\t\v\f\n; '\0'", str[start + 1]))
			break ;
		start++;
	}
	return (start);
}

int	get_end_index_expan(char *str, int start)
{
	t_quotes	quote;

	quote.is_single = false;
	quote.is_double = false;
	while (str[start])
	{
		set_quote_flag(&quote, str[start]);
		if (str[start] == '$' && !quote.is_single
			&& !find_char("\" '/~+=%^{}:\t\v\f\n; '\0'", str[start + 1]))
			break ;
		start++;
	}
	return (start);
}

char	*strjoin_new_var(char *temp_str, char *expanded_str, int count)
{
	char	*temp;

	temp = NULL;
	if (count > 1 && expanded_str)
	{
		temp = ft_strjoin(expanded_str, temp_str);
		if (temp)
			free(expanded_str);
	}
	else
		temp = ft_strdup(temp_str);
	if (temp)
		free(temp_str);
	return (temp);
}
