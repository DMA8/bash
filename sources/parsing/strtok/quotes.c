/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:05 by arashido          #+#    #+#             */
/*   Updated: 2023/11/28 10:07:15 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_unmatched_quotes(char *str)
{
	bool	is_single;
	bool	is_double;

	is_single = false;
	is_double = false;
	while (*str)
	{
		if (*str == '\'' && !is_double)
			is_single = !is_single;
		else if (*str == '"' && !is_single)
			is_double = !is_double;
		str++;
	}
	return (is_single || is_double);
}

void	set_quote_flag(t_quotes *value, char c)
{
	if (c == '\'' && value->is_double == false)
		value->is_single = !value->is_single;
	else if (c == '"' && value->is_single == false)
		value->is_double = !value->is_double;
}
