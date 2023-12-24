/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:56 by arashido          #+#    #+#             */
/*   Updated: 2023/11/28 10:06:36 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	char *get_env_val(env, search_var)
	{
		search for search_var in env, get the value and return ;
	}
	// here I wanted to create function for env token and values to copy and depending on the token I wanted to find its value but with Env most executor part works that's I think it is better you do this part.
*/

static char	*get_env_var(char *str, int start)
{
	char	*search_var;
	char	*env_var;

	env_var = NULL;
	search_var = ft_substr(str, start + 1, get_search_var_end(str, start)
		- start);
	printf("search_var: %s\n", search_var);
	if (search_var && search_var[0] == '?' && search_var[1] == '\0')
		env_var = ft_itoa(g_error_status);
	if (search_var)
	{
		env_var = ft_strdup("arashido");
		// here I just hard code it except this we should call the funtion here get_env_val();
		free(search_var);
	}
	if (env_var == NULL)
	{
		return (ft_strdup(""));
		free(search_var);
	}
	return (env_var);
}

static char	*new_expanded_str(char *str)
{
	int		i;
	char	*expanded_str;
	char	*temp_str;
	int		count;

	i = 0;
	count = 0;
	expanded_str = NULL;
	temp_str = NULL;
	while (str[i] && ++count)
	{
		if (str[i] == '$' && !find_char("\" '/~+=%^{}:\t\v\f\n; '\0'", str[i
				+ 1]))
		{
			temp_str = get_env_var(str, i);
			i = get_search_var_end(str, i) + 1;
		}
		else
		{
			temp_str = ft_substr(str, i, get_end_index_expan(str, i) - i);
			i = get_end_index_expan(str, i);
		}
		expanded_str = strjoin_new_var(temp_str, expanded_str, count);
	}
	return (expanded_str);
}

char	*final_expanded_str(char *str)
{
	char	*final_str;
	char	*expand_temp;

	final_str = ft_strdup(str); // make a copy of final string
	while (needs_expansion(final_str) == true)
	// case for nested nested expansions,
	// we need to keep expanding till there is nothing left
	{
		expand_temp = new_expanded_str(final_str);
		free(final_str);
		final_str = ft_strdup(expand_temp);
		free(expand_temp);
	}
	free(str);
	return (final_str);
}

static t_token	*expand_new_token_node(char *arg)
// create a token node out of the expanded string
{
	t_token *tmp;

	tmp = (t_token *)malloc(sizeof(t_token));
	if (tmp)
	{
		tmp->arg = ft_strdup(arg);
		tmp->type = WORD;
		// assign type to work always for every expanded string
		tmp->next = NULL;
	}
	return (tmp);
}

// We want to expand the token then add it to tokenlist
void	expand_token(t_token **tokenlist, char *str)
{
	char	**temp;
	int		index;
	char	*expanded_str;

	expanded_str = ft_strdup(str);
	expanded_str = final_expanded_str(expanded_str); // expand the string
	temp = ft_space(expanded_str);
	// we may get from the env variables a string with spaces and we want to remove them
	index = -1;
	while (temp[++index])
	// for every word from temp we add to the list a new token node
	{
		if (ft_strcmp("", temp[index]) == 0) // dont add empty strings
			continue ;
		add_token_node(tokenlist, expand_new_token_node(temp[index]));
		// add to token list
	}
	free_array(temp);
	if (expanded_str)
		free(expanded_str);
}
