/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:12:46 by arashido          #+#    #+#             */
/*   Updated: 2023/11/30 19:06:30 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_redirs(t_redirections *redirs)
{
	t_redirections	*temp;
	int				total;

	total = 0;
	temp = redirs;
	while (temp)
	{
		total++;
		temp = temp->next;
	}
	return (total);
}

t_command	*create_scmnd_node(t_token *start, t_token *end)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->cmd = NULL;
	command->redirections = NULL;
	command->args = NULL;
	fill_scmnd(command, start, end); // list
	if (command->args)
	{
		command->cmd = ft_strdup(command->args[0]);
		// copy of command name
		command->total_args = ft_array_len(command->args);
		// counting number of arguments
	}
	command->total_redirs = count_redirs(command->redirections);
	// total redirections
	return (command);
}

static void	add_token_to_args(t_command *scommand, t_token *current_token)
{
	char	**temp_array;

	if (scommand->args == NULL)
	{
		scommand->args = (char **)malloc(sizeof(char *) * 2);
		scommand->args[0] = ft_strdup(current_token->arg);
		scommand->args[1] = NULL;
	}
	else
	{
		temp_array = (char **)malloc(sizeof(char *) * 2);
		temp_array[0] = ft_strdup(current_token->arg); // make a copy
		temp_array[1] = NULL;
		scommand->args = ft_join(scommand->args, temp_array);
		// this function frees the first parameter
		free_array(temp_array);
	}
}

void	fill_scmnd(t_command *scommand, t_token *start, t_token *end)
{
	t_token	*current_token;

	current_token = start;
	while (current_token && current_token != end->next)
	{
		if (current_token->type == REDIR)
		// take the redirection token and the token after which will be the file name
		{
			// if (!current_token->next)
			// 	return ;
			fill_redirs(scommand, current_token, current_token->next);
			current_token = current_token->next->next;
		}
		while (current_token && (current_token != end->next
				&& current_token->type != REDIR))
		{
			add_token_to_args(scommand, current_token);
			// mainly uses join array
			current_token = current_token->next;
		}
	}
}

int	count_pipes(t_token *start) // count pipes
{
	int i;
	t_token *temp;

	temp = start;
	i = 1;
	while (temp)
	{
		if (temp->type == PIPE)
			i++;
		temp = temp->next;
	}
	return (i);
}

t_command	**create_commands(t_token *start)
{
	t_command	**arr_cmd;
	t_token		*temp_start;
	t_token		*end;
	int			i;

	arr_cmd = (t_command **)malloc(sizeof(t_command *) * (count_pipes(start)
			+ 1));
	if (!arr_cmd)
		printf("Allocation not working");
	i = -1;
	temp_start = start;
	while (++i < count_pipes(start))
	{
		end = temp_start;
		while (end->next != NULL && end->next->type != PIPE)
			end = end->next;
		arr_cmd[i] = create_scmnd_node(temp_start, end);
		// create simple command
		if (end->next != NULL)
			temp_start = end->next->next;
		else
			temp_start = NULL;
	}
	arr_cmd[i] = NULL;
	return (arr_cmd);
}
