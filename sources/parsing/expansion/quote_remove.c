/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:28:20 by arashido          #+#    #+#             */
/*   Updated: 2023/11/28 10:06:42 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_chars(char *str)
{
	int			i;
	int			count;
	t_quotes	quotes;

	quotes.is_single = false;
	quotes.is_double = false;
	i = -1;
	count = 0;
	while (str[++i])
	{
		set_quote_flag(&quotes, str[i]);
		if ((str[i] == '"' && !quotes.is_single) || (str[i] == '\''
				&& !quotes.is_double))
			continue ;
		count++;
	}
	return (count);
}

char	*remove_quotes(char *str, int in)
{
	char		*new_str;
	int			i;
	int			j;
	t_quotes	quotes;

	quotes.is_single = false;
	quotes.is_double = false;
	i = -1;
	j = 0;
	new_str = (char *)malloc(sizeof(char *) * (count_chars(str) + 1));
	while (str[++i])
	{
		set_quote_flag(&quotes, str[i]);
		if ((str[i] == '"' && !quotes.is_single) || (str[i] == '\''
				&& !quotes.is_double))
			continue ;
		new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	if (in == 1)
		safe_free(str);
	return (new_str);
}

void	token_quote_removal(t_token *tokenlist)
{
	t_token	*temp;

	temp = tokenlist;
	while (temp)
	{
		if (temp->type == REDIR && ft_strcmp(temp->arg, "<<") == 0
			&& temp->next)
		{
			temp = temp->next->next;
			continue ;
		}
		if (temp->type == WORD)
			temp->arg = remove_quotes(temp->arg, 1);
		temp = temp->next;
	}
}
