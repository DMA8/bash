/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediractions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:21:25 by arashido          #+#    #+#             */
/*   Updated: 2023/11/30 18:26:45 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redirections	*get_to_last(t_redirections *lst)
{
	t_redirections	*to_last;

	to_last = lst;
	while (to_last != NULL && to_last->next != NULL)
		to_last = to_last->next;
	return (to_last);
}

static void	add_to_redir_list(t_redirections **redirList,
		t_redirections *redirNode)
{
	t_redirections	*to_last;

	if (*redirList == NULL)
	{
		*redirList = redirNode;
	}
	else
	{
		to_last = get_to_last(*redirList);
		to_last->next = redirNode;
	}
}

static t_redir_type	assign_redir_type(char *arg)
{
	t_redir_type	type;

	if (ft_strcmp(arg, "<") == 0)
		type = REDIR_IN;
	else if (ft_strcmp(arg, ">") == 0)
		type = REDIR_OUT;
	else if (ft_strcmp(arg, ">>") == 0)
		type = REDIR_APPEND;
	else
		type = HEREDOC;
	return (type);
}

void	fill_redirs(t_command *scommand, t_token *redir, t_token *file)
{
	t_redirections	*new_redir;

	// allocate memory for this redirection struct
	new_redir = (t_redirections *)malloc(sizeof(t_redirections));
	// assign type
	new_redir->type = assign_redir_type(redir->arg);
	new_redir->file = ft_strdup(file->arg);
	new_redir->next = NULL;
	// add the node to the redir
	add_to_redir_list(&scommand->redirections, new_redir);
}
