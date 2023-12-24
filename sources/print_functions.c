/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:25:19 by arashido          #+#    #+#             */
/*   Updated: 2023/11/30 18:34:31 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_array(char **array, char *name)
{
	int i;

	i = 0;
	if(!array && !*array)
		return ;
	while (array[i])
	{
		printf("%s[%d] = %s\n", name, i, array[i]);
		i++;
	}
}

static char *getType(t_cmdtype type)
{
	if(type == WORD)
		return ("WORD");
	else if(type == REDIR)
		return ("REDIR");
	else if(type == PIPE)
		return ("PIPE");
	else
		return ("ERROR");
}

void print_tokenlist(t_token *tokenlist)
{
	t_token *temp;

	temp = tokenlist;
	while (temp)
	{
		printf("\033[0;32m%s: \033[0m", getType(temp->type));
		printf("%s\n", temp->arg);
		temp = temp->next;
	}
}


static char *getRedirType(t_redir_type type)
{
	if(type == REDIR_IN)
		return ("REDIR_IN");
	else if(type == REDIR_OUT)
		return ("REDIR_OUT");
	else if(type == REDIR_APPEND)
		return ("REDIR_APPEND");
	else if(type == HEREDOC)
		return ("HEREDOC");
	else
		return ("ERROR");
}

void print_commands(t_command **array_of_commands)
{
	int i;

	i = 0;
	int counter = 1;
	while (array_of_commands[i] != NULL)
	{
		// printf("here");/
		printf("\033[0;33mSimple Command [%d]\n\033[0m", i + 1);
		t_redirections *temp = array_of_commands[i]->redirections;
		if(array_of_commands[i]->cmd)
			printf("\033[0;32marray_of_commands[%d]->cmd =  \033[0m%s\n", i, array_of_commands[i]->cmd);
		print_array(array_of_commands[i]->args, "\033[0;32marg\033[0m");
		while(temp)
		{
			printf("\033[0;32m[%d] REDIR_TYPE:\033[0m  %s\n", counter, getRedirType(temp->type));
			printf("\033[0;32m[%d] FILENAME:\033[0m %s\n", counter, temp->file);
			temp = temp->next;
			counter++;
		}
		i++;
	}
}