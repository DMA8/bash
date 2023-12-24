/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:06:07 by arashido          #+#    #+#             */
/*   Updated: 2023/11/30 18:51:43 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*get_to_last(t_token *lst)
{
	t_token	*to_last;

	to_last = lst;
	while (to_last != NULL && to_last->next != NULL)
		to_last = to_last->next;
	return (to_last);
}

void	add_token_node(t_token **tokenlist, t_token *tokenNode)
// add token to list
{
	t_token *to_last;

	if (*tokenlist)
	{
		to_last = get_to_last(*tokenlist);
		to_last->next = tokenNode;
		tokenNode->next = NULL;
	}
	else
	{
		*tokenlist = tokenNode;
	}
}

static t_cmdtype	assign_t_token_type(char *arg)
{
	t_cmdtype	type;

	if (ft_strcmp(arg, "<") == 0)
		type = REDIR;
	else if (ft_strcmp(arg, ">") == 0)
		type = REDIR;
	else if (ft_strcmp(arg, ">>") == 0)
		type = REDIR;
	else if (ft_strcmp(arg, "<<") == 0)
		type = REDIR;
	else if (ft_strcmp(arg, "|") == 0)
		type = PIPE;
	else
		type = WORD;
	return (type);
}

t_token	*new_token_node(char *arg)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (node)
	{
		node->arg = ft_strdup(arg);            // make copy of arguments
		node->type = assign_t_token_type(arg); // assign type
		node->next = NULL;
	}
	return (node);
}

t_token	*create_token_list(char **tokens)
{
	int		i;
	bool	is_heredoc;

	t_token *tokenlist; // create a list
	is_heredoc = false;
	tokenlist = NULL; // initialise
	i = -1;
	while (tokens[++i])
	{
		if (needs_expansion(tokens[i]) == true && is_heredoc == false)
		{
			expand_token(&tokenlist, tokens[i]);
			continue ;
		}
		is_heredoc = false;
		if (tokens[i] && ft_strcmp("", tokens[i]) != 0)
			add_token_node(&tokenlist, new_token_node(tokens[i]));
		if (ft_strcmp("<<", tokens[i]) == 0)
			is_heredoc = true;
	}
	return (tokenlist);
}
