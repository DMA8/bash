/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:11:16 by arashido          #+#    #+#             */
/*   Updated: 2023/11/30 18:56:28 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error_status = 0;

int	getcmd(char *prefix, char **buf)
{
	buf[0] = readline(prefix);
	if (buf[0] == 0)
		return (-1);
	add_history(buf[0]);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*line;

	// int		i;
	// char	**tmp = NULL;
	(void)ac;
	(void)av;
	(void)env;
	// i = 0;
	// while (tmp[i])
	// {
	// 	printf("%s\n", tmp[i]);
	// 	i++;
	// }
	// return (0);
	while (1)
	{
		getcmd("minishell> ", &line);
		if (!line)
			break;
		if (*line != '\0')
			parse(line);
		// free(line);
	}
	return (0);
}
