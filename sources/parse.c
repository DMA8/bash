/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:25:42 by arashido          #+#    #+#             */
/*   Updated: 2023/11/30 19:06:02 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_delimiter(char *str)
{
	char	**temp_tokens;
	char	**final_tokens;
	char	**next_tokens;
	int		i;

	i = -1;
	temp_tokens = ft_space(str);
	if (temp_tokens == NULL)
	{
		return (NULL);
	}
	print_array(temp_tokens, "\033[0;32mafter_spaces_removed\033[0m");
	while (temp_tokens[++i] != NULL)
	{
		if (i == 0)
			final_tokens = ft_strtok(temp_tokens[i]);
		else
		{
			next_tokens = ft_strtok(temp_tokens[i]);
			final_tokens = ft_join(final_tokens, next_tokens);
			free_array(next_tokens);
		}
	}
	return (free_array(temp_tokens), final_tokens);
}

t_token	*ft_tokenise(char **str_tokens)
{
	t_token	*tokenlist;

	if (!str_tokens)
		return (false);
	tokenlist = create_token_list(str_tokens);
	if (tokenlist == NULL)
		return (tokenlist);
	if (token_syntax_check(tokenlist) == false)
	{
		g_error_status = 127;
		return (NULL);
	}
	token_quote_removal(tokenlist);
	return (tokenlist);
}

void	parse(char *line)
{
	char		**temp_array;
	t_token		*tokenlist;
	t_command	**array_of_commands;

	temp_array = NULL;
	temp_array = ft_delimiter(line);
	if (temp_array == NULL)
		return;
	print_array(temp_array, "\033[0;32marray before tokenlist\033[0m");//print the array;
	tokenlist = ft_tokenise(temp_array);
	if (tokenlist == NULL)
		return;
	printf("\033[0;33mTOKENLIST:\n\033[0m");
	print_tokenlist(tokenlist); //print the tokenlist;
	array_of_commands = create_commands(tokenlist);
	if (array_of_commands == NULL)
		return;
	print_commands(array_of_commands); //print the commands;
	free_array(temp_array);
}
