/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:04:25 by arashido          #+#    #+#             */
/*   Updated: 2023/11/28 10:06:29 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_sytnax(t_token *headtoken)
{
	t_token	*temp;

	temp = headtoken;
	while (temp && temp->next != NULL)
	{
		if (temp->type == REDIR && temp->next->type != WORD)
			return (printf("Bash: syntax error near unexpected token `%s'\n",
					temp->arg), false);
		if (temp->type == PIPE && !(temp->next->type == WORD
				|| temp->next->type == REDIR))
			return (printf("Bash: syntax error near unexpected token `%s'\n",
					temp->arg), false);
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		if (temp->type != WORD)
			return (printf("Bash: syntax error near token `newline'\n"), false);
	}
	return (true);
}

bool	token_syntax_check(t_token *headtoken)
{
	if (!headtoken)
		return (false);
	if (headtoken && headtoken->type == PIPE) // first is PIPE return syntax
	{
		return (printf("Bash: syntax error near unexpected token `%s'\n",
				headtoken->arg), false);
	}
	if (check_sytnax(headtoken) == false)
		return (false);
	return (true);
}
